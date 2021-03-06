#include "LogModel.h"
#include <QDebug>

LogModel::LogModel(const QStringList& headers)
    : mHeaders(headers)
{
}

int LogModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return mHeaders.size();
}

QVariant LogModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            return mHeaders[section];
        } else {
            return QVariant(section+1);
        }
    }
    return QVariant();
}

int LogModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return mEntries.size();
}

QVariant LogModel::data(const QModelIndex& index, int role) const
{
    if (role == MultiLineRole)
    {
        QString columnHeader = mHeaders[index.column()];
        return mEntries[index.row()].isPartMultiline(columnHeader);
    }
    if (role == Qt::CheckStateRole && mHeaders[index.column()] == "IS_MULTILINE")
    {
        return QVariant(mEntries[index.row()].isPartMultiline("CONTENT") ? Qt::Checked : Qt::Unchecked);
    } else
        if (role == Qt::DisplayRole || role == Qt::ToolTipRole)
        {
            QString columnHeader = mHeaders[index.column()];
            return mEntries[index.row()].getPart(columnHeader);
        }
    return QVariant();
}

Qt::ItemFlags LogModel::flags(const QModelIndex &index) const
{
    if (mHeaders[index.column()] == "HAS_ADDITIONAL_DATA")
    {
        return QAbstractTableModel::flags(index) | Qt::ItemIsUserCheckable;
    }
    return QAbstractTableModel::flags(index);
}

void LogModel::addRow(const LogEntry &entry)
{
    emit beginInsertRows(QModelIndex(), mEntries.size(), mEntries.size());
    mEntries.append(entry);
    emit endInsertRows();
}

void LogModel::mergeLastRow(const LogEntry &entry)
{
    mEntries.last().merge(entry);
    emit dataChanged(index(mEntries.size(), 0), index(mEntries.size(), mHeaders.size()));
}

