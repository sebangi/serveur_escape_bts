#ifndef ENIGMEBUTTON_H
#define ENIGMEBUTTON_H

/** \file enigmebutton.h
 * \brief Fichier de déclaration de la classe EnigmeButton.
 * \author Sébastien Angibaud
 */

#include "entete/enigme.h"

#include <QPushButton>

/**
 * \class EnigmeButton
 * \brief Classe décrivant un bouton permettant de sélectionner ou non une énigme.
 * \author Sébastien Angibaud
 */
class EnigmeButton : public QPushButton
{
public:
    /** \brief Type représentant un ensemble de pointeur sur des EnigmeButton. */
    typedef std::vector<EnigmeButton*> type_ensemble_enigme_bouton;

    /** \brief Type représentant un itérateur constant sur un ensemble de pointeur sur des EnigmeButton. */
    typedef type_ensemble_enigme_bouton::const_iterator enigme_bouton_const_iterator;

    /** \brief Type représentant un itérateur sur un ensemble de pointeur sur des EnigmeButton. */
    typedef type_ensemble_enigme_bouton::iterator enigme_bouton_iterator;

public:
    EnigmeButton( const Enigme & enigme, QWidget *parent = 0);
    ~EnigmeButton();

    void inverser();
    const Enigme & enigme() const;

    bool est_actif() const;
    void activer();
    void desactiver();

private:
    /** \brief L'énigme correspondant au bouton. */
    Enigme m_enigme;

    /** \brief Indique si l'énigme est sélectionnée. */
    bool m_est_actif;
};

#endif // ENIGMEBUTTON_H
