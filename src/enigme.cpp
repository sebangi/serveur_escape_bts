/**
 * \file enigme.cpp
 * \brief Fichier d'implémentation de la classe Enigme.
 * \author Sébastien Angibaud
 */

#include "entete/enigme.h"

#include <iostream>

/** --------------------------------------------------------------------------------------
 * \brief Constructeur de la classe Enigme.
 * \param id L'identifiant de l'énigme.
 * \param nom Le nom de l'énigme.
 * \param temps Le temps attribué à l'énigme.
 * \param valide Indique si l'énigme est valide, i.e. en état de fonctionnement.
 */
Enigme::Enigme( int id, QString nom, int temps, bool valide )
    : m_id(id), m_nom(nom), m_temps(temps), m_valide(valide)
{
}

/** --------------------------------------------------------------------------------------
 * \brief Accesseur du nom de l'énigme.
 * \return Le nom de l'énigme.
 */
QString Enigme::nom() const
{
    return m_nom;
}

/** --------------------------------------------------------------------------------------
 * \brief Accesseur du temps accordé pour l'énigme.
 * \return Le temps attribué à l'énigme.
 */
int Enigme::temps() const
{
    return m_temps;
}

/** --------------------------------------------------------------------------------------
 * \brief Accesseur de l'état de validité de l'énigme.
 * \return \b True si l'énigme est valide, \b False sinon.
 */
bool Enigme::valide() const
{
    return m_valide;
}

/** --------------------------------------------------------------------------------------
 * \brief Accesseur de l'identifiant de l'énigme.
 * \return L'identifiant de l'énigme
 */
int Enigme::id() const
{
    return m_id;
}
