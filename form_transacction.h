#ifndef FORM_TRANSACCTION_H
#define FORM_TRANSACCTION_H

#include <QAbstractItemModel>

class form_transacction : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit form_transacction(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // FORM_TRANSACCTION_H
