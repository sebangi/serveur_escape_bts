#include "entete/enigmebutton.h"

#include <QStyle>

EnigmeButton::EnigmeButton(const Enigme & enigme, QWidget *parent)
    : QPushButton(parent), m_enigme(enigme)
{
    setText( m_enigme.nom() );
    desactiver();
}

EnigmeButton::~EnigmeButton()
{

}

void EnigmeButton::inverser()
{
    if( m_est_actif )
        desactiver();
    else
        activer();
}

void EnigmeButton::activer()
{
    m_est_actif = true;
    setObjectName("EnigmeButtonSelectionne");
    style()->unpolish(this);
    style()->polish(this);
}

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

