#include "mot.h"

Mot::Mot(int idmot, QString monNom, definition def, QList<QString> lstTag) :
    defMot(def)
{
    //defMot(def);
    motid = idmot;
    nom = monNom;
    //ajouter liste tag
    tabTag = QList<QString>(lstTag);
}

Mot::Mot():
    nom(""), defMot(""), tabTag()
{

}

Mot::~Mot()
{
    //delete defMot;
}

QString Mot::getNom()
{
    return nom;
}

QString Mot::getDefinition()
{
    QString copie = defMot.getDefinition();
    return copie;
}

QList<QString> Mot::getLstTag()
{
    return tabTag;
}

void Mot::ajouterTag(QString nouveauTag)
{
    tabTag.append(nouveauTag);
}

void Mot::remplacerDef(QString newDef)
{
    defMot.changeDef(newDef);
}

void Mot::AfficheMot()
{
    qDebug() << "mot: " + nom;
    qDebug() << defMot.toString();
    qDebug() << "les différents tags associés sont: ";
    for(int i=0; i<tabTag.size(); i++)
    {
        qDebug() << tabTag.value(i);
    }

}
