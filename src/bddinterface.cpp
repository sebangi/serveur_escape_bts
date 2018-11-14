#include "entete/bddinterface.h"

#include <iostream>
#include <QtSql>

#define q2c(string) string.toStdString()

// Initialisation de la variable membre statique
BddInterface* BddInterface::m_instance = NULL;

BddInterface::BddInterface()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");

    m_db.setHostName("217.128.90.45");
    m_db.setUserName("2019_escape_user");
    m_db.setPassword("Dijkstra");
    m_db.setDatabaseName("2019_escape_bts");

    if( m_db.open() )
        std::cout << "Vous êtes maintenant connecté à " << q2c(m_db.hostName()) << std::endl;
    else
        std::cout << "La connexion a échouée, désolé" << std::endl;
}

/** --------------------------------------------------------------------------------------
 * \brief Destructeur de la classe AfficheurInterface.
 */
BddInterface::~BddInterface()
{
    if(m_db.isOpen())
        m_db.close();

    m_instance = NULL;
}

/** --------------------------------------------------------------------------------------
 * \brief Accesseur de l'instance singleton AfficheurInterface.
 * \return Le pointeur sur le singleton AfficheurInterface.
 */
BddInterface* BddInterface::instance()
{
    if ( m_instance == NULL )
        m_instance = new BddInterface();

    return m_instance;
}

/** --------------------------------------------------------------------------------------
 * \brief Teste si la connexion à la base de données est correctement établie.
 * \return \b True si la connexion est établie, \b False sinon.
 */
bool BddInterface::connexionEtablie() const
{
    if ( m_instance == NULL )
        return false;

    if ( ! m_instance->m_db.isOpen() )
        m_instance->m_db.open();

    return m_instance->m_db.isOpen();
}

type_enigmes BddInterface::get_enigmes() const
{
    type_enigmes enigmes;

    if( connexionEtablie() )
    {
        QSqlQuery query;
        if(query.exec("SELECT * FROM enigme"))
            while(query.next())
            {
                enigmes.push_back( Enigme( query.value(0).toInt(),
                                           query.value(1).toString(),
                                           query.value(2).toInt(),
                                           query.value(3).toBool() ) );
            }
    }

    return enigmes;
}

