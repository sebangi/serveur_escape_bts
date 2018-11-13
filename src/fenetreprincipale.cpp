#include "entete/fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::FenetrePrincipale)
{
    m_ui->setupUi(this);

    creer_widgets();
    init_widgets();

    resize(QSize(800,400));
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete m_ui;
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
    QStyle* style = QApplication::style();

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
    zone_equipe_en_cours_lay->setSpacing(10);

    m_chronometre_lcd.resize(8);
    for ( unsigned int i = 0; i != 8; ++i )
    {
        if ( i == 2 || i == 6 )
        {
            QLabel * deux_points_label = new QLabel( ":" );
            zone_equipe_en_cours_lay->addWidget( deux_points_label);
        }
        else if ( i == 4 )
        {
            QLabel * deux_points_label = new QLabel( " / " );
            zone_equipe_en_cours_lay->addWidget( deux_points_label);
        }

        m_chronometre_lcd[i] = new QLCDNumber();
        zone_equipe_en_cours_lay->addWidget( m_chronometre_lcd[i]);
    }

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

    QLabel * prochaine_partie_label = new QLabel( "PROCHAINE PARTIE" );
    prochaine_partie_label->setObjectName("TitreSection");
    prochaine_partie_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    prochaine_partie_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    zone_prochaine_partie_lay->addWidget(prochaine_partie_label, 1);

    QWidget * zone_prochaine_equipe = new QWidget(this);
    QHBoxLayout * zone_prochaine_equipe_lay = new QHBoxLayout();
    zone_prochaine_equipe_lay->setMargin(10);
    zone_prochaine_equipe_lay->setSpacing(10);

    for ( unsigned int i = 1; i != 5; ++i )
    {
        EnigmeButton * unEnigmeButton = new EnigmeButton( i, this );
        zone_prochaine_equipe_lay->addWidget( unEnigmeButton );
    }

    zone_prochaine_equipe->setLayout(zone_prochaine_equipe_lay);

    zone_prochaine_partie_lay->addWidget(zone_prochaine_equipe,1);
    zone_prochaine_partie->setLayout(zone_prochaine_partie_lay);

    // CONFIGURATION DU WIDGET CENTRAL
    m_ui->centralLayout->setMargin(0);
    m_ui->centralLayout->setSpacing(0);

    m_ui->centralLayout->addWidget(zone_partie_en_cours,1);
    m_ui->centralLayout->addWidget(zone_prochaine_partie,1);
}
