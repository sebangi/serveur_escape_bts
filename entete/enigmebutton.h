#ifndef ENIGMEBUTTON_H
#define ENIGMEBUTTON_H

#include "entete/enigme.h"

#include <QPushButton>

class EnigmeButton : public QPushButton
{
public:
    EnigmeButton( const Enigme & enigme, QWidget *parent = 0);
    ~EnigmeButton();

    void inverser();
    const Enigme & enigme() const;

    bool est_actif() const;

private:
    void activer();
    void desactiver();

private:
    Enigme m_enigme;
    bool m_est_actif;
};

#endif // ENIGMEBUTTON_H
