#-------------------------------------------------
#
# Project created by QtCreator 2018-09-27T09:56:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serveur_escape_bts
TEMPLATE = app

DESTDIR = ../serveur_escape_bts
OBJECTS_DIR = .obj
MOC_DIR     = .moc

SOURCES += main.cpp\
        src/fenetreprincipale.cpp \
        src/enigmebutton.cpp

HEADERS  += \
    entete/fenetreprincipale.h \
    entete/enigmebutton.h

FORMS    += fenetreprincipale.ui

DISTFILES += \
    stylesheet.qss \
    Doxyfile

RESOURCES += \
    ressources.qrc
