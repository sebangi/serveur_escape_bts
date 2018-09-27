#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include <vector>

namespace Ui {
    class FenetrePrincipale;
}

class FenetrePrincipale : public QMainWindow
{
        Q_OBJECT

    public:
        explicit FenetrePrincipale(QWidget *parent = 0);
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

        /** \brief Un pointeur sur le label des énigmes de la partie en cours. */
        QLabel * m_enigmes_en_cours_label;
};

#endif // FENETREPRINCIPALE_H
