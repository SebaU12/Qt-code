#include "form_transacction.h"

form_transacction::form_transacction(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant form_transacction::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex form_transacction::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex form_transacction::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int form_transacction::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int form_transacction::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant form_transacction::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
