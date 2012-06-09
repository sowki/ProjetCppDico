#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H
#include <QList>
#include "mot.h"
#include <QDebug>
class Dictionnaire
{
private:
    QList<Mot> liste;
public:
    Dictionnaire();
    void Demarrer();
    void construireMot(int idmot, QString nom, QString Def, QList<QString> tabTag);
    void afficherMots();

};

#endif // DICTIONNAIRE_H
