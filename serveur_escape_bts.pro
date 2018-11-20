#-------------------------------------------------
#
# Project created by QtCreator 2018-09-27T09:56:20
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serveur_escape_bts
TEMPLATE = app

DESTDIR = ../serveur_escape_bts
OBJECTS_DIR = .obj
MOC_DIR     = .moc

SOURCES += main.cpp\
        src/fenetreprincipale.cpp \
        src/enigmebutton.cpp \
        src/bddinterface.cpp \
        src/enigme.cpp \
        src/utils.cpp \
        src/enigmelabel.cpp \
        src/ensembleenigmesboutons.cpp \
        src/serveur.cpp

HEADERS  += \
    entete/fenetreprincipale.h \
    entete/enigmebutton.h \
    entete/bddinterface.h \
    entete/enigme.h \
    entete/defines.h \
    entete/utils.h \
    entete/enigmelabel.h \
    entete/ensembleenigmesboutons.h \
    entete/serveur.h

FORMS    += fenetreprincipale.ui

DISTFILES += \
    stylesheet.qss \
    Doxyfile

RESOURCES += \
    ressources.qrc
