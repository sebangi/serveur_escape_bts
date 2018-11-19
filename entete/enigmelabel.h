#ifndef ENIGMELABEL_H
#define ENIGMELABEL_H

#include "entete/enigme.h"

#include <QLabel>

class EnigmeLabel : public QLabel
{
public:
    /** \brief Un ensemble d'e pointeur sur Enigme'EnigmeButton. */
    typedef std::vector<EnigmeLabel*> type_ensemble_enigme_label;

public:
    EnigmeLabel( const Enigme & enigme, QWidget *parent = 0);
    ~EnigmeLabel();

    const Enigme & enigme() const;

    bool est_reussi() const;
    void set_reussi( bool valeur );

    bool est_selectionne() const;
    void set_selectionne( bool valeur );

private:
    void mise_a_jour_forme();

private:
    /** \brief L'énigme correspondant au bouton. */
    Enigme m_enigme;

    /** \brief Indique si l'énigme est réussi. */
    bool m_reussi;

    /** \brief Indique si l'énigme est selectionne. */
    bool m_selectionne;
};

#endif // ENIGMELABEL_H
