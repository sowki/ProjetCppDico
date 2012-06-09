#include "dictionnaire.h"
#include "mot.h"
#include <QString>
Dictionnaire::Dictionnaire()
{
    liste = QList<Mot>();
}

void Dictionnaire::construireMot(int idmot, QString nom, QString Def, QList<QString> tabTag)
{
    definition maDef = definition(Def);
    Mot nouveauMot = Mot(idmot, nom,maDef,tabTag);
    liste.append(nouveauMot);


}

void Dictionnaire::afficherMots()
{
    for(int ind = 0; ind < liste.length(); ind++)
    {
      liste.value(ind).AfficheMot();
    }
}

void Dictionnaire::Demarrer()
{

}
