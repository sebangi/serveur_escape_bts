#ifndef ENIGME_H
#define ENIGME_H

/** \file enigme.h
 * \brief Fichier de déclaration de la classe enigme.
 * \author Sébastien Angibaud
 */

#include <QString>
#include <vector>

/**
 * \class Enigme.
 * \brief Classe décrivant une énigme.
 * \author Sébastien Angibaud
 */
class Enigme
{
public:
    /** \brief Type décrivant un ensemble d'énigmes. */
    typedef std::vector<Enigme> type_enigmes;

public:
    Enigme( int id, QString nom, int temps, bool valide );


    QString nom() const;
    int temps() const;
    bool valide() const;
    int id() const;

private:
    /** \brief Identifiant de l'énigme. */
    int m_id;

    /** \brief Le nom de l'énigme. */
    QString m_nom;

    /** \brief Le temps accordé à l'énigme. */
    int m_temps;

    /** \brief Indique si l'énigme est valide, i.e en état de fonctionnement. */
    bool m_valide;
};

#endif // ENIGME_H
