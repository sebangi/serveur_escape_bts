/**
 * \file fenetreprincipale.cpp
 * \brief Fichier d'implémentation de la classe FenetrePrincipale.
 * \author Sébastien Angibaud
 */

#include "entete/fenetreprincipale.h"

#include "entete/enigme.h"
#include "entete/utils.h"
#include "ui_fenetreprincipale.h"

#include <iostream>

/** --------------------------------------------------------------------------------------
 \brief Constructeur de la classe FenetrePrincipale.
 \param parent Le pointeur sur le widget parent.
*/
FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::FenetrePrincipale)
{
    m_ui->setupUi(this);

    creer_widgets();
    init_widgets();

    resize(QSize(800,400));
    this->move(100,10);

    m_bdd = BddInterface::instance();
}

/** --------------------------------------------------------------------------------------
 \brief Destruction de la classe FenetrePrincipale.
*/
FenetrePrincipale::~FenetrePrincipale()
{
    delete m_ui;
    delete m_bdd;
}

/** --------------------------------------------------------------------------------------
 \brief Création des différents widgets.
*/
void FenetrePrincipale::creer_widgets()
{

}

/** --------------------------------------------------------------------------------------
 \brief Initialisation des différents widgets.
*/
void FenetrePrincipale::init_widgets()
{
    setWindowTitle("Serveur ESCAPE BTS");
    m_ui->centralWidget->setObjectName("CentralWidget");

    // ZONE PARTIE EN COURS
    QWidget * zone_partie_en_cours = new QWidget(this);
    zone_partie_en_cours->setObjectName("SectionPartieEnCours");
    QVBoxLayout * zone_partie_en_cours_lay = new QVBoxLayout();
    zone_partie_en_cours_lay->setMargin(10);
    zone_partie_en_cours_lay->setSpacing(10);

    QLabel * partie_en_cours_label = new QLabel( "PARTIE EN COURS" );
    partie_en_cours_label->setObjectName("TitreSection");
    partie_en_cours_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    partie_en_cours_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    zone_partie_en_cours_lay->addWidget(partie_en_cours_label, 1);

    m_equipe_en_cours_label = new QLabel( "Equipe non renseignée" );
    m_equipe_en_cours_label->setObjectName("MonLabel");
    m_equipe_en_cours_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_equipe_en_cours_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    zone_partie_en_cours_lay->addWidget(m_equipe_en_cours_label, 1);

    QWidget * zone_temps= new QWidget(this);
    QHBoxLayout * zone_equipe_en_cours_lay = new QHBoxLayout();
    zone_equipe_en_cours_lay->setMargin(10);
    zone_equipe_en_cours_lay->setSpacing(0);

    m_chronometre_label = new QLabel( "00:00" );
    m_chronometre_label->setObjectName("Chronometre");
    m_chronometre_label->setFixedHeight(80);
    m_chronometre_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    zone_equipe_en_cours_lay->addWidget( m_chronometre_label);

    QLabel * deux_points_label = new QLabel( "temps passé | temps restant" );
    deux_points_label->setObjectName("ChronometreSeparation");
    deux_points_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    zone_equipe_en_cours_lay->addWidget( deux_points_label);

    m_temps_total_label = new QLabel( "05:00" );
    m_temps_total_label->setObjectName("Chronometre");
    m_temps_total_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    zone_equipe_en_cours_lay->addWidget( m_temps_total_label);

    zone_temps->setLayout(zone_equipe_en_cours_lay);
    zone_partie_en_cours_lay->addWidget(zone_temps, 1);

    m_enigmes_en_cours_label = new QLabel( "Énigmes : 0 / 0" );
    m_enigmes_en_cours_label->setObjectName("MonLabel");
    m_enigmes_en_cours_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_enigmes_en_cours_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    zone_partie_en_cours_lay->addWidget(m_enigmes_en_cours_label, 1);

    zone_partie_en_cours->setLayout(zone_partie_en_cours_lay);

    // ZONE PROCHAINE PARTIE
    QWidget * zone_prochaine_partie = new QWidget(this);
    zone_prochaine_partie->setObjectName("SectionProchainePartie");
    QVBoxLayout * zone_prochaine_partie_lay = new QVBoxLayout();
    zone_prochaine_partie_lay->setMargin(10);
    zone_prochaine_partie_lay->setSpacing(10);

    QLabel * prochaine_partie_label = new QLabel( "PROCHAINE ÉQUIPE" );
    prochaine_partie_label->setObjectName("TitreSection");
    prochaine_partie_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    prochaine_partie_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    zone_prochaine_partie_lay->addWidget(prochaine_partie_label, 1);

    QWidget * infos_prochaine_partie = new QWidget(this);
    QHBoxLayout * infos_prochaine_partie_lay = new QHBoxLayout();
    infos_prochaine_partie_lay->setMargin(10);
    infos_prochaine_partie_lay->setSpacing(0);

    QLabel * label_equipe = new QLabel( "Équipe :" );
    label_equipe->setObjectName("MonLabelInfo");
    label_equipe->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label_equipe->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    infos_prochaine_partie_lay->addWidget(label_equipe, 1);

    m_prochaine_equipe_editText = new QTextEdit();
    m_prochaine_equipe_editText->setObjectName("EnigmeTextEdit");
    m_prochaine_equipe_editText->setFixedHeight(40);
    m_prochaine_equipe_editText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_prochaine_equipe_editText->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    connect(m_prochaine_equipe_editText, SIGNAL (textChanged()),this, SLOT (on_nom_equipe_changed()));
    infos_prochaine_partie_lay->addWidget(m_prochaine_equipe_editText, 20);

    QLabel * label_nb_enigmes = new QLabel( "Nombre d'énigmes :" );
    label_nb_enigmes->setObjectName("MonLabelInfo");
    label_nb_enigmes->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label_nb_enigmes->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    infos_prochaine_partie_lay->addWidget(label_nb_enigmes, 1);

    m_label_nb_enigmes = new QLabel( "0" );
    m_label_nb_enigmes->setObjectName("nombreEnigmes");
    m_label_nb_enigmes->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_label_nb_enigmes->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    infos_prochaine_partie_lay->addWidget(m_label_nb_enigmes, 1);

    QLabel * label_temps_accorde = new QLabel( "Temps accordé :" );
    label_temps_accorde->setObjectName("MonLabelInfo");
    label_temps_accorde->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label_temps_accorde->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    infos_prochaine_partie_lay->addWidget(label_temps_accorde, 1);

    m_label_temps_accorde = new QLabel( "00:00" );
    m_label_temps_accorde->setObjectName("tempsAccorde");
    m_label_temps_accorde->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_label_temps_accorde->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    infos_prochaine_partie_lay->addWidget(m_label_temps_accorde, 1);

    infos_prochaine_partie->setLayout(infos_prochaine_partie_lay);
    zone_prochaine_partie_lay->addWidget(infos_prochaine_partie,1);

    QWidget * zone_prochaines_enigmes = new QWidget(this);
    m_zone_prochaines_enigmes_lay = new QGridLayout();
    m_zone_prochaines_enigmes_lay->setMargin(10);
    m_zone_prochaines_enigmes_lay->setSpacing(10);

    Enigme::type_enigmes enigmes = BddInterface::instance()->get_enigmes();
    for ( unsigned int i = 0; i != enigmes.size(); ++i )
    {
        EnigmeButton * unEnigmeButton = new EnigmeButton( enigmes[i], this );
        m_enigmes_prochaine_equipe.push_back(unEnigmeButton);
        connect(unEnigmeButton, SIGNAL (released()),this, SLOT (on_choix_enigme()));
        m_zone_prochaines_enigmes_lay->addWidget( unEnigmeButton, (i) / 5, (i) % 5 );
    }

    zone_prochaines_enigmes->setLayout(m_zone_prochaines_enigmes_lay);
    zone_prochaine_partie_lay->addWidget(zone_prochaines_enigmes,1);

    QWidget * boutons_prochaine_partie = new QWidget(this);
    QHBoxLayout * boutons_prochaine_partie_lay = new QHBoxLayout();
    boutons_prochaine_partie_lay->setMargin(10);
    boutons_prochaine_partie_lay->setSpacing(0);

    m_enregistrer_nouvelle_equipe = new QPushButton( "Enregistrer" );
    m_enregistrer_nouvelle_equipe->setObjectName("MonBouton");
    m_enregistrer_nouvelle_equipe->setFixedWidth(200);
    m_enregistrer_nouvelle_equipe->setFixedHeight(50);
    m_enregistrer_nouvelle_equipe->setEnabled(false);
    connect(m_enregistrer_nouvelle_equipe, SIGNAL (released()),this, SLOT (on_enregistrer_equipe()));
    boutons_prochaine_partie_lay->addWidget(m_enregistrer_nouvelle_equipe, 1);

    m_demarrer_nouvelle_equipe = new QPushButton( "Démarrer" );
    m_demarrer_nouvelle_equipe->setObjectName("MonBouton");
    m_demarrer_nouvelle_equipe->setFixedWidth(200);
    m_demarrer_nouvelle_equipe->setFixedHeight(50);
    m_demarrer_nouvelle_equipe->setEnabled(false);
    connect(m_demarrer_nouvelle_equipe, SIGNAL (released()),this, SLOT (on_demarrer_equipe()));
    boutons_prochaine_partie_lay->addWidget(m_demarrer_nouvelle_equipe, 1);

    boutons_prochaine_partie->setLayout(boutons_prochaine_partie_lay);
    zone_prochaine_partie_lay->addWidget(boutons_prochaine_partie);

    zone_prochaine_partie->setLayout(zone_prochaine_partie_lay);

    // CONFIGURATION DU WIDGET CENTRAL
    m_ui->centralLayout->setMargin(0);
    m_ui->centralLayout->setSpacing(10);

    m_ui->centralLayout->addWidget(zone_partie_en_cours,1);
    m_ui->centralLayout->addWidget(zone_prochaine_partie,1);
}

/** --------------------------------------------------------------------------------------
 \brief Met à jour de l'affichage du temps accordé à la prochaine partie.
*/
void FenetrePrincipale::mise_a_jour_temps_accorde()
{
    int temps = 0;
    std::vector<EnigmeButton*>::const_iterator it;

    for ( it = m_enigmes_prochaine_equipe.begin();
          it != m_enigmes_prochaine_equipe.end();
          ++it )
    {
        if ( (*it)->est_actif() )
            temps += (*it)->enigme().temps();
    }

    m_label_temps_accorde->setText( utils::secondeToQSting( temps ) );
}

/** --------------------------------------------------------------------------------------
 \brief Mise à jour de l'affichage du nombre d'énigmes à la prochaine partie.
*/
void FenetrePrincipale::mise_a_jour_nb_enigmes()
{
    m_label_nb_enigmes->setText( QString::number( calcul_nb_enigmes() ) );
}

/** --------------------------------------------------------------------------------------
 \brief Calcul du nombre d'énigmes à la prochaine partie.
*/
int FenetrePrincipale::calcul_nb_enigmes() const
{
    int nb = 0;
    std::vector<EnigmeButton*>::const_iterator it;

    for ( it = m_enigmes_prochaine_equipe.begin();
          it != m_enigmes_prochaine_equipe.end();
          ++it )
    {
        if ( (*it)->est_actif() )
            nb++;
    }

    return nb;
}

/** --------------------------------------------------------------------------------------
 * \brief Fonction appelée lorsqu'une énigme est sélectionnée ou désélectionné.
 */
void FenetrePrincipale::on_choix_enigme()
{
    QWidget *buttonWidget = qobject_cast<QWidget*>(sender());
    if (!buttonWidget)
        return;

    EnigmeButton *clickedButton = (EnigmeButton*)(buttonWidget);

    if (!clickedButton)
        return;

    if ( clickedButton->enigme().valide() )
    {
        clickedButton->inverser();
        mise_a_jour_temps_accorde();
        mise_a_jour_nb_enigmes();
        mise_a_jour_enregistrer();
    }
}

/** --------------------------------------------------------------------------------------
 * \brief Mise à jour de l'état du bouton "Enregistrer".
 */
void FenetrePrincipale::mise_a_jour_enregistrer()
{
    if ( ! m_prochaine_equipe_editText->toPlainText().isEmpty() &&
         calcul_nb_enigmes() != 0 )
        m_enregistrer_nouvelle_equipe->setEnabled(true);
    else
        m_enregistrer_nouvelle_equipe->setEnabled(false);
}

/** --------------------------------------------------------------------------------------
 * \brief Fonction appelée lorsque le nom de l'équipe change.
 */
void FenetrePrincipale::on_nom_equipe_changed()
{
    mise_a_jour_enregistrer();
}

/** --------------------------------------------------------------------------------------
 * \brief Fonction appelée lorsqu'on enregistre la prochaine équipe.
 */
void FenetrePrincipale::on_enregistrer_equipe()
{
    m_enregistrer_nouvelle_equipe->setEnabled(false);
    m_demarrer_nouvelle_equipe->setEnabled(true);
    m_prochaine_equipe_editText->setEnabled(false);

    std::vector<EnigmeButton*>::const_iterator it;
    for ( it = m_enigmes_prochaine_equipe.begin();
          it != m_enigmes_prochaine_equipe.end();
          ++it )
        (*it)->setEnabled(false);
}

/** --------------------------------------------------------------------------------------
 * \brief Fonction appelée lorsqu'on démarre la partie de la prochaine équipe.
 */
void FenetrePrincipale::on_demarrer_equipe()
{
    m_demarrer_nouvelle_equipe->setEnabled(false);
    m_prochaine_equipe_editText->setText("");
    m_prochaine_equipe_editText->setEnabled(true);
    std::vector<EnigmeButton*>::const_iterator it;
    for ( it = m_enigmes_prochaine_equipe.begin();
          it != m_enigmes_prochaine_equipe.end();
          ++it )
    {
        (*it)->desactiver();
        (*it)->setEnabled(true);
    }
}
