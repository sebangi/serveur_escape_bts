#include "entete/enigmelabel.h"

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

/** --------------------------------------------------------------------------------------
 * \brief Retourne si l'énigme est réussie.
 * \return \b True si l'énigme est réussi, \b False sinon.
 */
bool EnigmeLabel::est_reussi() const
{
    return m_reussi;
}

/** --------------------------------------------------------------------------------------
 * \brief Indique que l'énigme est réussi.
 */
void EnigmeLabel::noter_reussi()
{
    m_reussi = true;
}
