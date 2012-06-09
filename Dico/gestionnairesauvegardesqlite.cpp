#include "GestionnaireSauvegardeSQLite.h"
#include <QDir>
#include <QFile>
#include <QSqlQuery>
#include "dictionnaire.h"
#include "mot.h"
#include <QtGlobal>
#include <QSqlError>
#include <QList>
#include <QDebug>

GestionnaireSauvegardeSQLite::GestionnaireSauvegardeSQLite(QObject* parent)
    : QObject(parent)
{
}


GestionnaireSauvegardeSQLite::~GestionnaireSauvegardeSQLite()
{
    if (m_db.isOpen()){
        m_db.close();
    }
}

void GestionnaireSauvegardeSQLite::chargerMotsContenant(QString souschaine, Dictionnaire *dico, bool effacerExistant)
{
    //on cherche en BDD les mots qui se rapportent �  la sous-chaine
    QString selectall = "SELECT motid, nomMot, texte, nomTag  FROM Mots, Tags, Definitions, Apourdef, Apourtag WHERE Mots.motid = Apourdef.FK_Motid AND Definitions.defid = Apourdef.FK_Defid AND Apourdef.apdid = Apourtag.FK_apdid AND Tags.tagid = Apourtag.FK_Tagid AND Mots.nomMot LIKE '"+ souschaine +"' ";
    QSqlQuery query = m_db.exec(selectall);
    m_db.commit();
    debugConsole(query);
    //on les ajoute dans le dico passé en parametre


    int motid;
    QString mot;
    QString texte;
    QList<QString> listag;


    //on prend le premier résultat
     query.first();
     motid = query.value(0).toInt();
     mot = query.value(1).toString();
     texte = query.value(2).toString();
     listag.append(query.value(3).toString());
     while (query.next())
     {
         if(motid == query.value(0).toInt())//si on est toujours sur le meme mot, on ne fait qu'ajouter le tag � la liste
         {
             listag.append(query.value(3).toString());
         }
         else
         {
             //on est sur un autre mot !
             //on crée le mot :
             dico->construireMot(motid, mot,texte,listag);
             //on se prépare pour le prochain mot
             motid = query.value(0).toInt();
             listag.clear();
             //on prépare le prochain mot
             mot = query.value(1).toString();
             texte = query.value(2).toString();
             listag.append(query.value(3).toString());
         }
     }
     //on prend le dernier résultat
     if(listag.length() > 0)
     {
         //on crée le mot :
         dico->construireMot(motid, mot,texte,listag);
     }


}

void GestionnaireSauvegardeSQLite::debugConsole(QSqlQuery &query)
{
    qDebug() << query.lastError().text();
    qDebug() << "Requete : " + query.lastQuery();
    qDebug() << "Nombre de résultats : " + query.size();
}


void GestionnaireSauvegardeSQLite::selectMot()
{
   QString select = "SELECT * FROM Mots";
   QSqlQuery query = m_db.exec(select);
   m_db.commit();

   while (query.next())
   {
            QString mot = query.value(0).toString();
            qDebug() << "Mot récupéré : " + mot;
   }

   debugConsole(query);
}

void GestionnaireSauvegardeSQLite::sauvegarderMot( Mot& mot)
{
    //�  refaire
    if (openDB() == false) {
        qWarning("Impossible de sauvegarder le mot " + mot.getNom().toLatin1() +" car la base n'est pas ouverte");
        return;
    }

    QSqlQuery query = m_db.exec("INSERT OR REPLACE INTO Mots(mot,def) VALUES (\""+mot.getNom()+"\" ,\""+mot.getDefinition()+"\")");
    m_db.commit();
    debugConsole(query);
}

void GestionnaireSauvegardeSQLite::chargerTout(Dictionnaire* dico, bool effacerExistant)
{
    QString selectall = "SELECT motid, nomMot, texte, nomTag  FROM Mots, Tags, Definitions, Apourdef, Apourtag WHERE Mots.motid = Apourdef.FK_Motid AND Definitions.defid = Apourdef.FK_Defid AND Apourdef.apdid = Apourtag.FK_apdid AND Tags.tagid = Apourtag.FK_Tagid ";
    QSqlQuery query = m_db.exec(selectall);
    m_db.commit();

        debugConsole(query);
        int motid;
        QString mot;
        QString texte;
        QList<QString> listag;

       //on prend le premier résultat
        query.first();
        motid = query.value(0).toInt();
        mot = query.value(1).toString();
        texte = query.value(2).toString();
        listag.append(query.value(3).toString());
        while (query.next())
        {
            if(motid == query.value(0).toInt())
            {
                listag.append(query.value(3).toString());
            }
            else
            {
                //on est sur un autre mot !
                //on crée le mot :
                dico->construireMot(motid, mot,texte,listag);
                //on se prépare pour le prochain mot
                motid = query.value(0).toInt();
                listag.clear();
                //on prépare le prochain mot
                mot = query.value(1).toString();
                texte = query.value(2).toString();
                listag.append(query.value(3).toString());
            }
        }
        //on prend le dernier résultat
        if(listag.length() > 0)
        {
            //on crée le mot :
            dico->construireMot(motid, mot,texte,listag);
        }


}

void GestionnaireSauvegardeSQLite::sauvegarderTout(Dictionnaire* dico, bool effacerPrecedent)
{
    /*if (openDB() == false) {
        qWarning("Impossible de sauvegarder car la base n'est pas ouverte");
        return;
    }
    if (effacerPrecedent) {
        m_db.exec("DROP TABLE Mots");
    }
    int wordCount = dico->getNbMots();
    for(int i=0;i<wordCount;i++) {
        sauvegarderMot(dico->getMotAtIndex(i));
    }
    m_db.close();
    */
}

void GestionnaireSauvegardeSQLite::initDB()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString filePath = QDir::currentPath() + "/dico.sqlite";
    qDebug() << filePath;
    m_db.setDatabaseName(filePath);
    if (QFile::exists(filePath) == false) {
        createTables();
        qDebug() << "Les tables ont été crées !" << endl;
    }
    openDB();

}

bool GestionnaireSauvegardeSQLite::openDB()
{
    if (m_db.isOpen() == false) {
        if (m_db.open() == false) {
            qCritical("Impossible d'ouvrir la base de données\n");
            qCritical(m_db.lastError().text().toLatin1());
            return false;
        }
    }

    return true;
}

bool GestionnaireSauvegardeSQLite::createTables()
{
    if (openDB()){
        //création de la table definition
        QString query("CREATE TABLE Definitions (defid INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE , texte TEXT);");
        QSqlQuery queryQSQL = m_db.exec(query);
        m_db.commit();

        //création de la table definition mots
        query ="CREATE TABLE Mots (motid INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE , nomMot VARCHAR(80)); ";
        queryQSQL = m_db.exec(query);
        m_db.commit();

        //création de la table tags
        query ="CREATE TABLE Tags (tagid INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE , nomTag VARCHAR(80)); ";
        queryQSQL = m_db.exec(query);
        m_db.commit();

        //création de la table apourdef
        query ="CREATE TABLE Apourdef (apdid INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE , FK_Motid INTEGER  NOT NULL, FK_Defid INTEGER  NOT NULL, FOREIGN KEY(FK_Motid) REFERENCES Mots(motid), FOREIGN KEY(FK_Defid) REFERENCES Definitions(defid)); ";
        queryQSQL = m_db.exec(query);
        m_db.commit();

        //création de la table apourtag
        query ="CREATE TABLE Apourtag (aptid INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE , FK_apdid INTEGER  NOT NULL, FK_Tagid INTEGER  NOT NULL, FOREIGN KEY(FK_apdid) REFERENCES Apourdef(apdid), FOREIGN KEY(FK_Tagid) REFERENCES Tag(tagid)); ";
        queryQSQL = m_db.exec(query);
        m_db.commit();
    }

    return true;
}
