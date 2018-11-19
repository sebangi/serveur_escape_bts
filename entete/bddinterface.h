#ifndef BDDINTERFACE_H
#define BDDINTERFACE_H

/** \file bddinterface.h
 * \brief Fichier de déclaration de la classe BddInterface.
 * \author Sébastien Angibaud
 */

#include <QSqlDatabase>

#include "entete/enigme.h"
#include "entete/enigmebutton.h"
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
    int get_id_derniere_equipe() const;
    void creer_partie( QString nom_equipe,
                       const EnigmeButton::type_ensemble_enigme_bouton & enigmes );

private:
    void connexion_bdd();

private:
    /** \brief Pointeur sur l'instance singleton BddInterface. */
    static BddInterface* m_instance;

    /** \brief Connecteur à la base MySQL. */
    QSqlDatabase m_db;
};

#endif // BDDINTERFACE_H
