#include "entete/enigmebutton.h"

EnigmeButton::EnigmeButton(unsigned int id, QWidget *parent)
    : QPushButton(parent), m_id(id)
{
    setText( QString::number(m_id) );
}

EnigmeButton::~EnigmeButton()
{

}

