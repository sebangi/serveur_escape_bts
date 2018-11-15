#ifndef UTILS_H
#define UTILS_H

/** \file utils.h
 * \brief Fichier de déclaration de la classe utils.
 * \author Sébastien Angibaud
 */

#include <QString>

/**
 * \class utils
 * \brief Classe regroupant les fonctions de bases utiles à l'application.
 * \author Sébastien Angibaud
 */
class utils
{
public:
    utils();

    static QString secondeToQSting( int seconde);
};

#endif // UTILS_H
