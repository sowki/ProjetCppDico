#include "definition.h"


definition::definition(QString texte)
{
    def = texte;
}

definition::definition(const definition &defAcopier)
{
    def = defAcopier.def;
}

QString definition::getDefinition()
{
    return def;
}

void definition::changeDef(QString txt)
{
    def=txt;
}

QString definition::toString()
{
    return"la definition est: " + def;
}
