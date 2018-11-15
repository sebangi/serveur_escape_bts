/**
 * \file EnigmeButton.cpp
 * \brief Fichier d'implémentation de la classe EnigmeButton.
 * \author Sébastien Angibaud
 */

#include "entete/enigmebutton.h"

#include <QStyle>

/** --------------------------------------------------------------------------------------
 * \brief Constructeur de la classe EnigmeButton.
 * \param enigme L'énigme associée au bouton.
 * \param parent Un poiteur sur le widget parent.
 */
EnigmeButton::EnigmeButton(const Enigme & enigme, QWidget *parent)
    : QPushButton(parent), m_enigme(enigme)
{
    setText( m_enigme.nom() );
    desactiver();
}

/** --------------------------------------------------------------------------------------
 * \brief Destructeur de la classe EnigmeButton.
 */
EnigmeButton::~EnigmeButton()
{

}

/** --------------------------------------------------------------------------------------
 * \brief Inverse l'état du bouton.
 */
void EnigmeButton::inverser()
{
    if( m_est_actif )
        desactiver();
    else
        activer();
}

/** --------------------------------------------------------------------------------------
 * \brief Active le bouton.
 */
void EnigmeButton::activer()
{
    m_est_actif = true;
    setObjectName("EnigmeButtonSelectionne");
    style()->unpolish(this);
    style()->polish(this);
}

/** --------------------------------------------------------------------------------------
 * \brief Désactive le bouton.
 */
void EnigmeButton::desactiver()
{
    m_est_actif = false;
    setObjectName("EnigmeButtonNonSelectionne");
    style()->unpolish(this);
    style()->polish(this);
}

bool EnigmeButton::est_actif() const
{
    return m_est_actif;
}

const Enigme & EnigmeButton::enigme() const
{
    return m_enigme;
}

