/**
 * \file utils.cpp
 * \brief Fichier d'implémentation de la classe Utils.
 * \author Sébastien Angibaud
 */

#include "entete/utils.h"

utils::utils()
{

}

/** --------------------------------------------------------------------------------------
 * \brief Fonction convertissant un nombre de secondes en QString de type "mm::ss".
 * \param seconde Le nombre de seconde à convertir.
 * \return La chaîne de type QString conertie.
 */
QString utils::secondeToQSting(int seconde)
{
    int min = seconde / 60;
    int sec = seconde % 60;

    QString s =
        QString::number( min/10 ) +
        QString::number( min%10 ) +
        ":" +
        QString::number( sec/10 ) +
        QString::number( sec%10 );

    return s;
}
