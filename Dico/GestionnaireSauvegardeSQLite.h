#ifndef GESTIONNAIRESAUVEGARDESQLITE_H
#define GESTIONNAIRESAUVEGARDESQLITE_H

#include "GestionnaireSauvegarde.h"
#include <QObject>
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtDebug>

class GestionnaireSauvegardeSQLite : public GestionnaireSauvegarde, public QObject
{

public:
    GestionnaireSauvegardeSQLite(QObject* parent = 0);
    ~GestionnaireSauvegardeSQLite();

    void sauvegarderTout(Dictionnaire* dico, bool effacerPrecedent=true);
    void chargerTout(Dictionnaire* dico, bool effacerExistant=false);
    void chargerMotsContenant(QString souschaine, Dictionnaire* dico, bool effacerExistant=false);
    void sauvegarderMot(Mot &mot);
    void initDB();
    void selectMot();




private:
    QSqlDatabase m_db;

private:
    bool openDB();
    bool createTables();
    void execInsert(QString request);
    void closeDB();
    void debugConsole(QSqlQuery &query);
};

#endif // GESTIONNAIRESAUVEGARDESQLITE_H
