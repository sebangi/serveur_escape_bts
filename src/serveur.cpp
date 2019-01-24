#include "entete/serveur.h"

#include <QtNetwork>
#include <stdlib.h>
#include <iostream>

#include "entete/fenetreprincipale.h"


//###############################################################################################################
// Constructeur
Serveur::Serveur(FenetrePrincipale * f)
:   m_tcp_serveur(0), m_network_session(0), m_blockSize(0), m_fenetre(f)
{
    QNetworkConfigurationManager manager;
    QNetworkConfiguration config = manager.defaultConfiguration();
    m_network_session = new QNetworkSession(config, this);

    // La méthode sessionOuverte sera appelée sur le signal opened
    connect(m_network_session, SIGNAL(opened()), this, SLOT(sessionOuverte()));

    // Ouverture de la session
    m_network_session->open();

    // La méthode connexionClient sera appelée sur le signal newConnection
    connect(m_tcp_serveur, SIGNAL(newConnection()), this, SLOT(connexionClient()));
}

//###############################################################################################################
// Méthode appelée lors de l'ouverture de session
void Serveur::sessionOuverte()
{
    m_tcp_serveur = new QTcpServer(this); // instanciation

    if (!m_tcp_serveur->listen(QHostAddress::Any, 53000)) // on écoute sur le port 53000
    {
        std::cout << "Le serveur n'a pas été correctement lancee." << std::endl;
    }
    else
    {
        std::cout << "Le serveur est pret \n\nIP: " << m_tcp_serveur->serverAddress().toString().toStdString()
                  << std::endl << "port: " << m_tcp_serveur->serverPort() << std::endl
                  <<  "Lancez l'application Client maintenant." << std::endl;
    }
}

//###############################################################################################################
// Méthode appelée lors de l'ouverture d'une connexion avec un client
void Serveur::connexionClient()
{
    // instanciation
    m_socket_client = m_tcp_serveur->nextPendingConnection();

    // La méthode lireTexte sera appelée sur le signal readyRead
    connect(m_socket_client, SIGNAL(readyRead()), this, SLOT(lireTexte2()));

}

//###############################################################################################################
// Traitement de la chaine de caractères recue
std::string Serveur::traiter_chaine( const std::string & s )
{
    std::string res;

    for ( unsigned int i = 0; i != s.size(); ++i )
        if ( ( (int)(s[i]) >= 48 && (int)(s[i]) <= 58 ) ||
             (int)(s[i]) == 65 ||
             (int)(s[i]) == 69 ||
             (int)(s[i]) == 71 ||
             (int)(s[i]) == 78 )
            res = res + s[i];

    return res;
}

//###############################################################################################################
// Teste la validoté de la chaine de caractères recue
void Serveur::tester_validite(const std::string & s)
{
    bool ok = false;
    int num_enigme;

    if ( s.size() >= 7 )
    {
        std::string debut(s,0,6);
        std::string fin(s,6,s.size()-6);

        if ( debut == "GAGNE:" )
        {
            QString qfin = QString::fromStdString(fin);
            num_enigme = qfin.toInt(&ok);
            std::cout << "numero enigme : " << num_enigme << std::endl;
        }
    }


    if ( ok )
    {
        std::cout << "MESSAGE VALIDE" << std::endl;
        m_fenetre->valider_enigme(num_enigme);
    }
    else
        std::cout << "ERREUR : FORMAT INVALIDE" << std::endl;

}

//###############################################################################################################
// Méthode appelée lors de la réception d'un texte
void Serveur::lireTexte2()
{
    std::cout << "---------------------" << std::endl;
    std::string s = m_socket_client->readAll().toStdString();
    std::string res = traiter_chaine(s);
    std::cout << "message recu :" << res << std::endl;

    tester_validite(res);

    m_socket_client->close();
}


//###############################################################################################################
// Méthode appelée lors de la réception d'un texte
void Serveur::lireTexte()
{
    QDataStream in(m_socket_client);
    in.setVersion(QDataStream::Qt_4_0);

    if (m_blockSize == 0) {
        if (m_socket_client->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> m_blockSize;
    }

    if (m_socket_client->bytesAvailable() < m_blockSize)
        return;

    QString texte;
    in >> texte;

    std::cout << texte.toStdString() << std::endl;
    m_blockSize = 0;

    m_socket_client->close();
}
