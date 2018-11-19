#ifndef ENSEMBLEENIGMESBOUTONS_H
#define ENSEMBLEENIGMESBOUTONS_H

#include <vector>
#include "entete/enigmebutton.h"

class EnsembleEnigmesBoutons : public std::vector<EnigmeButton*>
{
public:
    EnsembleEnigmesBoutons();

    int get_nb_enigmes_selectionnees() const;
    int get_temps_accorde() const;
};

#endif // ENSEMBLEENIGMESBOUTONS_H
