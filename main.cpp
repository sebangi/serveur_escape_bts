/**
 * \file main.cpp
 * \brief Fichier d'implémentation du programme principal.
 * \author Sébastien Angibaud
 */

#include "entete/fenetreprincipale.h"

#include <QApplication>
#include <QFile>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QFile File("stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    QApplication a(argc, argv);
    a.setStyleSheet(StyleSheet);

    FenetrePrincipale w;
    w.show();

    return a.exec();
}
