#include <QtGui/QApplication>
#include "mainwindow.h"
#include "definition.h"
#include "mot.h"
#include "dictionnaire.h"
#include "GestionnaireSauvegardeSQLite.h"

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;

    w.show();$/

    /*QList<QString> tag = QList<QString>();
    tag.append("test1");
    tag.append("lolilol");
    definition def("je suis la def");
    Mot testing = Mot("Mon premier mot",def, tag);
    testing.AfficheMot();


    QString nom = "Motus";
    QString defi ="i am the def";
    dico.construireMot(nom,defi,tag);
    dico.construireMot("blabla","blou",tag);
    dico.afficherMots();*/

    Dictionnaire dico;
    GestionnaireSauvegardeSQLite SQL;
    SQL.initDB();
    SQL.selectMot();
    //SQL.selectMot("orange (fruit)");
    SQL.chargerTout(&dico);
    dico.afficherMots();

    dico.modifierMot();
    //return a.exec();
}
