#ifndef BDDINTERFACE_H
#define BDDINTERFACE_H

/** \file bddinterface.h
 * \brief Fichier de déclaration de la classe BddInterface.
 * \author Sébastien Angibaud
 */

#include <QSqlDatabase>
#include <set>

#include "entete/enigme.h"
#include "entete/enigmebutton.h"
#include "entete/ensembleenigmesboutons.h"

/**
 * \class BddInterface
 * \brief Classe permettant d'interagir avec la base de données.
 * \author Sébastien Angibaud
 */
class BddInterface
{
private:
    BddInterface();

public:
    ~BddInterface();

public:
    static BddInterface* instance();

    bool connexionEtablie() const;
    Enigme::type_enigmes get_enigmes() const;
    QString get_nom_equipe( int id_equipe ) const;
    int get_temps_accorde( int id_equipe ) const;
    int get_temps_passe( int id_equipe ) const;
    bool est_terminee( int id_equipe ) const;
    int get_id_derniere_equipe() const;
    void creer_partie( QString nom_equipe,
                       const EnsembleEnigmesBoutons & enigmes );
    void demarrer_partie( int id_equipe );
    void finir_partie( int id_equipe, int score );
    void reussir_enigme(int id_equipe, int num_enigme);
    std::set<int> get_enigmes_selectionnees( int id_equipe );

private:
    void connexion_bdd();

private:
    /** \brief Pointeur sur l'instance singleton BddInterface. */
    static BddInterface* m_instance;

    /** \brief Connecteur à la base MySQL. */
    QSqlDatabase m_db;
};

#endif // BDDINTERFACE_H
