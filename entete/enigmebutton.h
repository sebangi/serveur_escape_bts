#ifndef ENIGMEBUTTON_H
#define ENIGMEBUTTON_H

#include <QPushButton>

class EnigmeButton : public QPushButton
{
public:
    EnigmeButton(unsigned int id, QWidget *parent = 0);
    ~EnigmeButton();

private:
    unsigned int m_id;
};

#endif // ENIGMEBUTTON_H
