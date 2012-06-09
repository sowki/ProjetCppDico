#ifndef GESTIONNAIRESAUVEGARDE_H
#define GESTIONNAIRESAUVEGARDE_H
#include <QString>
#include <dictionnaire.h>
#include <mot.h>
class GestionnaireSauvegarde
{
public:
    GestionnaireSauvegarde();
    virtual void sauvegarderTout(Dictionnaire* dico, bool effacerPrecedent=true) = 0;
    virtual void chargerTout(Dictionnaire* dico, bool effacerExistant=false) = 0;
    virtual void chargerMotsContenant(QString souschaine, Dictionnaire* dico, bool effacerExistant=false) = 0;
    virtual void sauvegarderMot(Mot& mot) = 0;
};

#endif // GESTIONNAIRESAUVEGARDE_H
