#ifndef VUERECHERCHEINSTANT_H
#define VUERECHERCHEINSTANT_H
#include <QAbstractListModel>
class vueRechercheInstant : public QAbstractListModel
{
Q_OBJECT

public:
    explicit vueRechercheInstant(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // VUERECHERCHEINSTANT_H
