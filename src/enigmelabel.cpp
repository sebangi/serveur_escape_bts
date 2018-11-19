#include "entete/enigmelabel.h"

#include <QStyle>

/** --------------------------------------------------------------------------------------
 * \brief Constructeur de la classe EnigmeLabel.
 * \param enigme L'énigme associée au bouton.
 * \param parent Un poiteur sur le widget parent.
 */
EnigmeLabel::EnigmeLabel(const Enigme & enigme, QWidget *parent)
    : QLabel(parent), m_enigme(enigme), m_reussi(false)
{
    setText( m_enigme.nom() );
}

/** --------------------------------------------------------------------------------------
 * \brief Destructeur de la classe EnigmeButton.
 */
EnigmeLabel::~EnigmeLabel()
{

}

const Enigme &EnigmeLabel::enigme() const
{
    return m_enigme;
}

/** --------------------------------------------------------------------------------------
 * \brief Retourne si l'énigme est réussie.
 * \return \b True si l'énigme est réussi, \b False sinon.
 */
bool EnigmeLabel::est_reussi() const
{
    return m_reussi;
}

/** --------------------------------------------------------------------------------------
 * \brief Initialise l'état de réussite de l'énigme.
 */
void EnigmeLabel::set_reussi( bool valeur )
{
    m_reussi = valeur;
    mise_a_jour_forme();
}

bool EnigmeLabel::est_selectionne() const
{
    return m_selectionne;
}

void EnigmeLabel::set_selectionne(bool valeur)
{
    m_selectionne = valeur;
    mise_a_jour_forme();
}


void EnigmeLabel::mise_a_jour_forme()
{
    if ( m_selectionne )
    {
        if ( m_reussi )
            setObjectName("LabelEnigmeEnCoursReussi");
        else
            setObjectName("LabelEnigmeEnCoursNonReussi");
    }
    else
        setObjectName("LabelEnigmeEnCoursNonSelectionne");

    style()->unpolish(this);
    style()->polish(this);
}
