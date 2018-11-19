#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

/** \file fenetreprincipale.h
 * \brief Fichier de déclaration de la classe FenetrePrincipale.
 * \author Sébastien Angibaud
 */

#include <QGridLayout>
#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include <QTextEdit>

#include <vector>

#include "entete/enigmebutton.h"
#include "entete/enigmelabel.h"
#include "entete/bddinterface.h"

namespace Ui {
    class FenetrePrincipale;
}

/**
 * \class FenetrePrincipale
 * \brief Classe décrivant la fenêtre principale de l'application.
 * \author Sébastien Angibaud
 */
class FenetrePrincipale : public QMainWindow
{
        Q_OBJECT

    public:
        explicit FenetrePrincipale(QWidget *parent = NULL);
        ~FenetrePrincipale();

    private slots:
        void on_choix_enigme();
        void on_nom_equipe_changed();
        void on_enregistrer_equipe();
        void on_demarrer_equipe();

    private:
        void creer_widgets();
        void init_widgets();
        void mise_a_jour_temps_accorde();
        void mise_a_jour_nb_enigmes();
        int calcul_nb_enigmes() const;
        void mise_a_jour_enregistrer();
        void commencer_partie();
        void enregistrer_prochaine_partie();

    private:
        /** \brief Un pointeur sur la Fenetre centrale. */
        Ui::FenetrePrincipale *m_ui;

        /** \brief Un pointeur sur l'interface à la base de données. */
        BddInterface * m_bdd;

        /** \brief Un pointeur sur le label de l'équipe en cours. */
        QLabel * m_equipe_en_cours_label;

        /** \brief Un pointeur sur le label du chronomètre. */
        QLabel * m_chronometre_label ;

        /** \brief Un pointeur sur le label du temps total. */
        QLabel * m_temps_total_label ;

        /** \brief Un pointeur sur le label de l'équipe en cours. */
        QTextEdit * m_prochaine_equipe_editText;

        /** \brief Un pointeur sur le label du nombre d'énigmes. */
        QLabel * m_label_nb_enigmes;

        /** \brief Un pointeur sur le label du temps accordé. */
        QLabel * m_label_temps_accorde;

        /** \brief Un pointeur sur le layout contenant les énigmes à choisir. */
        QGridLayout * m_zone_prochaines_enigmes_lay;

        /** \brief Un pointeur sur le layout contenant les énigmes en cours. */
        QGridLayout * m_zone_enigmes_en_cours_lay;

        /** \brief Un pointeur sur le bouton d'enregistrement d'une nouvelle équipe. */
        QPushButton * m_enregistrer_nouvelle_equipe;

        /** \brief Un pointeur sur le bouton de démarrage d'une nouvelle partie. */
        QPushButton * m_demarrer_nouvelle_equipe;

        /** \brief Un tableau des pointeurs sur les boutons de choix des énigmes. */
        EnigmeButton::type_ensemble_enigme_bouton m_enigmes_prochaine_equipe;

        /** \brief Un tableau des pointeurs sur les labels des énigmes en cours. */
        EnigmeLabel::type_ensemble_enigme_label m_enigmes_en_cours;
};

#endif // FENETREPRINCIPALE_H
