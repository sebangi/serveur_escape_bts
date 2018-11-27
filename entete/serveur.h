#ifndef SERVER_H
#define SERVER_H

#include <QObject>

class QTcpServer;
class QTcpSocket;
class QNetworkSession;

class Serveur : public QObject{
    Q_OBJECT

public:
    Serveur();

private slots:
    void sessionOuverte();
    void connexionClient();
    void lireTexte();
    void lireTexte2();

    private:
    void tester_validite(const std::string & s);
    std::string traiter_chaine( const std::string & s );

private:
    QTcpServer *m_tcp_serveur; // La socket général
    QTcpSocket *m_socket_client; // La socket client
    QNetworkSession *m_network_session; // La session de connexion
    quint16 m_blockSize;
};

#endif
