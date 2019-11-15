/**
 * \file bddinterface.cpp
 * \brief Fichier d'implémentation de la classe BddInterface.
 * \author Sébastien Angibaud
 */

#include "entete/bddinterface.h"
#include "entete/defines.h"

#include <iostream>

#include <QtSql>

// Initialisation de la variable membre statique
BddInterface* BddInterface::m_instance = NULL;

/** --------------------------------------------------------------------------------------
 * \brief Constructeur de la classe BddInterface.
 */
BddInterface::BddInterface()
{
    connexion_bdd();
}

/** --------------------------------------------------------------------------------------
 * \brief Destructeur de la classe BddInterface.
 */
BddInterface::~BddInterface()
{
    std::cout << "Fermeture de la connexion à la base de données" << std::endl;

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

Enigme::type_enigmes BddInterface::get_enigmes() const
{
    Enigme::type_enigmes enigmes;

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
    else
    {
        enigmes.push_back( Enigme(1, "Enigme 1", 180, true) );
        enigmes.push_back( Enigme(2, "Enigme 2", 180, true) );
        enigmes.push_back( Enigme(3, "Enigme 3", 180, true) );
        enigmes.push_back( Enigme(4, "Enigme 4", 180, true) );
        enigmes.push_back( Enigme(5, "Enigme 5", 180, true) );
    }

    return enigmes;
}

QString BddInterface::get_nom_equipe(int id_equipe) const
{
    if( connexionEtablie() )
    {
        QSqlQuery query;
        query.prepare( "SELECT nom FROM equipe "
                       "WHERE id = :id_equipe");
        query.bindValue(":id_equipe", id_equipe);

        if(query.exec())
            while(query.next())
            {
                return query.value(0).toString();
            }
    }

    return "non renseignée";
}

int BddInterface::get_temps_accorde(int id_equipe) const
{
    if( connexionEtablie() )
    {
        QSqlQuery query;
        query.prepare( "SELECT temps_accorde FROM equipe "
                       "WHERE id = :id_equipe");
        query.bindValue(":id_equipe", id_equipe);

        if(query.exec())
            while(query.next())
            {
                return query.value(0).toInt();
            }
    }

    return 0;
}

int BddInterface::get_temps_passe(int id_equipe) const
{
    if( connexionEtablie() )
    {
        QSqlQuery query;
        query.prepare( "SELECT CURRENT_TIMESTAMP - heure_depart FROM equipe "
                       "WHERE id = :id_equipe");
        query.bindValue(":id_equipe", id_equipe);

        if(query.exec())
            while(query.next())
            {
                return query.value(0).toInt();
            }
    }

    return 0;
}

bool BddInterface::est_terminee(int id_equipe) const
{
    if( connexionEtablie() )
    {
        QSqlQuery query;
        query.prepare( "SELECT est_termine FROM equipe "
                       "WHERE id = :id_equipe");
        query.bindValue(":id_equipe", id_equipe);

        if(query.exec())
            while(query.next())
            {
                return query.value(0).toBool();
            }
    }

    return true;
}

int BddInterface::get_id_derniere_equipe() const
{
    if( connexionEtablie() )
    {
        QSqlQuery query;
        if(query.exec("SELECT MAX(id) FROM equipe"))
            while(query.next())
                return query.value(0).toInt();
    }

    return C_MAUVAIS_ID;
}

void BddInterface::creer_partie
 ( QString nom_equipe,
   const EnsembleEnigmesBoutons & enigmes )
{
    if( connexionEtablie() )
    {
        QSqlQuery query;
        query.prepare( "INSERT INTO equipe (nom, nb_enigmes, temps_accorde) "
                       "VALUES (:nom, :nb_enigmes, :temps_accorde)");
        query.bindValue(":nom", nom_equipe);
        query.bindValue(":nb_enigmes", enigmes.get_nb_enigmes_selectionnees());
        query.bindValue(":temps_accorde", enigmes.get_temps_accorde());

        bool ok = query.exec();
        std::cout << "query :" <<  ok << std::endl;
     }

    int id_equipe = get_id_derniere_equipe();
    std::cout << "id=" << id_equipe << std::endl;
    if ( id_equipe != C_MAUVAIS_ID )
    {
        for ( EnsembleEnigmesBoutons::const_iterator it = enigmes.begin();
              it != enigmes.end(); ++it )
            if ( (*it)->est_actif() )
            {
                QSqlQuery query;
                query.prepare( "INSERT INTO enigme_equipe (id_enigme, id_equipe) "
                               "VALUES (:id_enigme, :id_equipe)");
                query.bindValue(":id_enigme", (*it)->enigme().id() );
                query.bindValue(":id_equipe", id_equipe);

                query.exec();
            }
    }
}

void BddInterface::demarrer_partie(int id_equipe)
{
    if( connexionEtablie() )
    {
        QSqlQuery query;

        query.prepare( "UPDATE equipe SET heure_depart=CURRENT_TIMESTAMP,est_en_cours=1 "
                       "WHERE id = :id_equipe");
        query.bindValue(":id_equipe", id_equipe);

        query.exec();
    }
}

void BddInterface::finir_partie(int id_equipe, int score)
{
    if( connexionEtablie() )
    {
        QSqlQuery query;

        query.prepare( "UPDATE equipe SET score=:score, heure_fin=CURRENT_TIMESTAMP,est_en_cours=0, est_termine=1 "
                       "WHERE id=:id_equipe");
        query.bindValue(":id_equipe", id_equipe);
        query.bindValue(":score", score);

        query.exec();
    }
}

void BddInterface::reussir_enigme(int id_equipe, int num_enigme)
{
    if( connexionEtablie() )
    {
        QSqlQuery query;

        query.prepare( "UPDATE equipe SET est_reussi=1 "
                       "WHERE id_equipe = :id_equipe AND id_enigme = :id_enigme");
        query.bindValue(":id_equipe", id_equipe);
        query.bindValue(":id_enigme", num_enigme);

        query.exec();
    }
}


std::set<int> BddInterface::get_enigmes_selectionnees(int id_equipe)
{
    std::set<int> resultat;

    if( connexionEtablie() )
    {
        QSqlQuery query;
        query.prepare( "SELECT id_enigme FROM enigme_equipe "
                       "WHERE id_equipe = :id_equipe");
        query.bindValue(":id_equipe", id_equipe);

        if(query.exec())
            while(query.next())
            {
                resultat.insert( query.value(0).toInt() );
            }
    }

    return resultat;
}

void BddInterface::connexion_bdd()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");

   // m_db.setHostName("217.128.90.45");
    m_db.setHostName("10.6.0.1");
    m_db.setUserName("2019_escape_user");
    m_db.setPassword("Dijkstra");
    m_db.setDatabaseName("2019_escape_bts");

    if( m_db.open() )
        std::cout << "Vous êtes maintenant connecté à " << q2c(m_db.hostName()) << std::endl;
    else
        std::cout << "La connexion a échouée, désolé" << std::endl;
}
