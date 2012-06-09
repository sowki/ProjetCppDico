#ifndef DEFINITION_H
#define DEFINITION_H
#include <QString>
class definition
{
public:
    definition(QString texte);
    definition(const definition&);
    QString getDefinition();
    QString toString();
    void changeDef(QString txt);
    //faire un constructeur par recopie quand il y aura l'image !
private:
    QString def;
    //image image;
};

#endif // DEFINITION_H
