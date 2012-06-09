#include "modelrecherche.h"

modelRecherche::modelRecherche(QObject *parent) :
QAbstractListModel(parent)
{
    monSQL = new GestionnaireSauvegardeSQLite();
    liste = new QList<QString>();
}

int modelRecherche::rowCount(const QModelIndex &parent) const
{
    return liste->length();
}

QVariant modelRecherche::data(const QModelIndex &index, int role) const
{
    int numLigne = index.row();
    int cpt = 0;


    switch(role)
    {
        case Qt::DisplayRole:
        for(int ind = 0; ind < liste->count(); ind++ )
        {
            return QVariant(liste->value(ind));
        }
    default:
            return QVariant();

    }
}

void modelRecherche::nouvelleRecherche(QString requete)
{
    liste->append("Test1");
    liste->append("Test2");
    liste->append("Test3");
    liste->append("Test4");
    liste->append("Test5");
}
