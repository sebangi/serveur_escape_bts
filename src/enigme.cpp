#include "entete/enigme.h"

#include <iostream>

Enigme::Enigme( int id, QString nom, int temps, bool valide )
    : m_id(id), m_nom(nom), m_temps(temps), m_valide(valide)
{
    std::cout << m_id << " "
              << m_nom.toStdString() << " "
              << m_temps << " "
              << m_valide << std::endl;
}

QString Enigme::nom() const
{
    return m_nom;
}

int Enigme::temps() const
{
    return m_temps;
}

bool Enigme::valide() const
{
    return m_valide;
}

int Enigme::id() const
{
    return m_id;
}
