#ifndef MODELRECHERCHE_H
#define MODELRECHERCHE_H
#include <QAbstractListModel>
#include "GestionnaireSauvegardeSQLite.h"
#include <QList>
class modelRecherche : public QAbstractListModel
{
        Q_OBJECT
private:
    GestionnaireSauvegardeSQLite *monSQL;
    QList<QString> *liste;
public:
    explicit modelRecherche(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void nouvelleRecherche(QString requete);
signals:

public slots:

};

#endif // MODELRECHERCHE_H
