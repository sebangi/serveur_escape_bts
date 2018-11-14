#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QGridLayout>
#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include <QTextEdit>

#include <vector>

#include "entete/enigmebutton.h"
#include "entete/BddInterface.h"

namespace Ui {
    class FenetrePrincipale;
}

class FenetrePrincipale : public QMainWindow
{
        Q_OBJECT

    public:
        explicit FenetrePrincipale(QWidget *parent = NULL);
        ~FenetrePrincipale();

    private slots:
        void on_choix_enigme();

    private:
        void creer_widgets();
        void init_widgets();
        void mise_a_jour_temps_accorde();
        void mise_a_jour_nb_enigmes();

    private:
        Ui::FenetrePrincipale *m_ui;

        BddInterface * m_bdd;

        /** \brief Un pointeur sur le label de l'équipe en cours. */
        QLabel * m_equipe_en_cours_label;

        /** \brief Un pointeur sur le label du chronomètre. */
        QLabel * m_chronometre_label ;

        /** \brief Un pointeur sur le label du temps total. */
        QLabel * m_temps_total_label ;

        /** \brief Un pointeur sur le label du décompte des énigmes de la partie en cours. */
        QLabel * m_enigmes_en_cours_label;

        /** \brief Un pointeur sur le label de l'équipe en cours. */
        QTextEdit * m_prochaine_equipe_editText;

        QLabel * m_label_nb_enigmes;

        QLabel * m_label_temps_accorde;

        /** \brief Un pointeur sur le layout contenant les énigmes à choisir. */
        QGridLayout * m_zone_prochaines_enigmes_lay;

        /** \brief Un tableau des pointeurs sur les boutons de choix des énigmes. */
        std::vector<EnigmeButton*> m_enigmes_prochaine_equipe;
};

#endif // FENETREPRINCIPALE_H
