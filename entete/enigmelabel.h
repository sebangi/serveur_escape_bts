#ifndef ENIGMELABEL_H
#define ENIGMELABEL_H

#include "entete/enigme.h"

#include <QLabel>

class EnigmeLabel : public QLabel
{
public:
    EnigmeLabel( const Enigme & enigme, QWidget *parent = 0);
    ~EnigmeLabel();

    const Enigme & enigme() const;

    bool est_reussi() const;
    void noter_reussi();

private:
    /** \brief L'énigme correspondant au bouton. */
    Enigme m_enigme;

    /** \brief Indique si l'énigme est réussi. */
    bool m_reussi;
};

#endif // ENIGMELABEL_H
