#include "entete/ensembleenigmesboutons.h"

EnsembleEnigmesBoutons::EnsembleEnigmesBoutons()
{

}

/** --------------------------------------------------------------------------------------
 \brief Calcul du nombre d'énigmes à la prochaine partie.
*/
int EnsembleEnigmesBoutons::get_nb_enigmes_selectionnees() const
{
    int nb = 0;
    const_iterator it;

    for ( it = begin(); it != end(); ++it )
    {
        if ( (*it)->est_actif() )
            nb++;
    }

    return nb;
}


/** --------------------------------------------------------------------------------------
 \brief Calcul du temps accordé à la prochaine partie.
*/
int EnsembleEnigmesBoutons::get_temps_accorde() const
{
    int temps = 0;
    const_iterator it;

    for ( it = begin(); it != end(); ++it )
    {
        if ( (*it)->est_actif() )
            temps += (*it)->enigme().temps();
    }

    return temps;
}

