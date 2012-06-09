#-------------------------------------------------
#
# Project created by QtCreator 2012-05-19T17:57:45
#
#-------------------------------------------------

QT       += core gui
QT       += core gui sql

TARGET = Dico
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gestionnairesauvegarde.cpp \
    gestionnairesauvegardesqlite.cpp \
    mot.cpp \
    dictionnaire.cpp \
    definition.cpp \
    modelrecherche.cpp

HEADERS  += mainwindow.h \
    ../../../Downloads/Interfaces_et_prog_objet (1)/GestionnaireSauvegardeSQLite.h \
    ../../../Downloads/Interfaces_et_prog_objet (1)/GestionnaireSauvegarde.h \
    gestionnairesauvegarde.h \
    gestionnairesauvegardesqlite.h \
    mot.h \
    dictionnaire.h \
    definition.h \
    modelrecherche.h

FORMS    += mainwindow.ui
