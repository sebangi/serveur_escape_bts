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
#include <QTimer>

#include <vector>

#include "entete/enigmebutton.h"
#include "entete/enigmelabel.h"
#include "entete/ensembleenigmesboutons.h"
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
        void valider_enigme(int num);

    private slots:
        void on_choix_enigme();
        void on_nom_equipe_changed();
        void on_enregistrer_equipe();
        void on_demarrer_equipe();
        void on_forcer_fin();
        void onFinTimer();

    private:
        void creer_widgets();
        void init_widgets();
        void mise_a_jour_temps_accorde();
        void mise_a_jour_temps_en_cours();
        void mise_a_jour_nb_enigmes();
        void mise_a_jour_enregistrer();
        void charger_partie_en_cours();
        void commencer_partie();
        void mise_a_jour_enigme_en_cours();
        void enregistrer_prochaine_partie();
        void terminer_partie();
        void calculer_score();

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

        /** \brief Un pointeur sur le bouton de démarrage d'une nouvelle partie. */
        QPushButton * m_terminer_partie;

        /** \brief L'ensemble des boutons de choix des énigmes. */
        EnsembleEnigmesBoutons m_enigmes_prochaine_equipe;

        /** \brief Un tableau des pointeurs sur les labels des énigmes en cours. */
        EnigmeLabel::type_ensemble_enigme_label m_enigmes_en_cours;

        /** \brief Identifiant de l'équipe en cours. */
        int m_id_equipe_en_cours;

        /** \brief Temps en seconde depuis le commencement de la partie. */
        int m_temps_en_cours;

        /** \brief Temps accordée à la partie. */
        int m_temps_accorde;

        /** \brief Nombre d'énigmes en cours. */
        int m_nb_enigmes_en_cours;

        /** \brief Nombre d'énigmes trouvées. */
        int m_nb_enigmes_trouvees;

        /** \brief Indique si la partie courante est terminée. */
        bool m_partie_courante_terminee;

        /** \brief Le timer pour le chronomètre. */
        QTimer *m_timer;
};

#endif // FENETREPRINCIPALE_H
