#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include <QTextEdit>

#include <vector>

#include "entete/enigmebutton.h"

namespace Ui {
    class FenetrePrincipale;
}

class FenetrePrincipale : public QMainWindow
{
        Q_OBJECT

    public:
        explicit FenetrePrincipale(QWidget *parent = NULL);
        ~FenetrePrincipale();

    private:
        void creer_widgets();
        void init_widgets();

    private:
        Ui::FenetrePrincipale *m_ui;

        /** \brief Un pointeur sur le label de l'équipe en cours. */
        QLabel * m_equipe_en_cours_label;

        /** \brief Un tableau des pointeurs sur les chiffres du chronomètre. */
        std::vector<QLCDNumber*> m_chronometre_lcd;

        /** \brief Un pointeur sur le label du décompte des énigmes de la partie en cours. */
        QLabel * m_enigmes_en_cours_label;

        /** \brief Un pointeur sur le label de l'équipe en cours. */
        QTextEdit * m_prochaine_equipe_editText;

        /** \brief Un tableau des pointeurs sur les boutons de choix des énigmes. */
        std::vector<EnigmeButton*> m_enigmes_prochaine_equipe;
};

#endif // FENETREPRINCIPALE_H
