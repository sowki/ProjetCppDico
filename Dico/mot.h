#ifndef MOT_H
#define MOT_H
#include <definition.h>
#include <QList>
#include <QDebug>
class Mot
{
public:
    Mot(int idmot, QString monNom, definition def, QList<QString> lstTag);
    Mot();
    QString getNom();
    QString getDefinition();
    QList<QString> getLstTag();
    void ajouterTag(QString nouveauTag);
    void remplacerDef(QString newDef);

    void AfficheMot();
    ~Mot();
private:
    int motid;
    QList<QString> tabTag;
    definition defMot;
    QString nom;
};

#endif // MOT_H
