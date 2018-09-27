#include "entete/fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::FenetrePrincipale)
{
    m_ui->setupUi(this);

    creer_widgets();
    init_widgets();

    resize(QSize(1200,900));
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

    // ZONE PARTIE EN COURS
    QWidget * zone_partie_en_cours = new QWidget(this);
    QVBoxLayout * zone_partie_en_cours_lay = new QVBoxLayout();
    zone_partie_en_cours_lay->setMargin(10);
    zone_partie_en_cours_lay->setSpacing(10);

    QLabel * partie_en_cours_label = new QLabel( "PARTIE EN COURS" );
    partie_en_cours_label->setObjectName("TitreSection");
    partie_en_cours_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    partie_en_cours_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    zone_partie_en_cours_lay->addWidget(partie_en_cours_label);

    QWidget * zone_equipe_en_cours = new QWidget(this);
    QHBoxLayout * zone_equipe_en_cours_lay = new QHBoxLayout();
    zone_equipe_en_cours_lay->setMargin(10);
    zone_equipe_en_cours_lay->setSpacing(10);

    m_equipe_en_cours_label = new QLabel( "Equipe non renseignée" );
    m_equipe_en_cours_label->setObjectName("NomEquipe");
    m_equipe_en_cours_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_equipe_en_cours_label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    zone_equipe_en_cours_lay->addWidget(m_equipe_en_cours_label);

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

    m_enigmes_en_cours_label = new QLabel( "Énigmes : 0 / 0" );
    m_enigmes_en_cours_label->setObjectName("EnigmesEnCours");
    m_enigmes_en_cours_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_enigmes_en_cours_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    zone_equipe_en_cours_lay->addWidget(m_enigmes_en_cours_label);

    zone_equipe_en_cours->setLayout(zone_equipe_en_cours_lay);

    zone_partie_en_cours_lay->addWidget(zone_equipe_en_cours);
    zone_partie_en_cours->setLayout(zone_partie_en_cours_lay);

    m_ui->centralLayout->setMargin(0);
    m_ui->centralLayout->setSpacing(0);

    m_ui->centralLayout->addWidget(zone_partie_en_cours,1);
    //m_ui->centralLayout->addWidget(s_vue_logs, 5);
}
