#include "LogModel.h"
#include <QDebug>
#include "LogRowColorizer.h"

LogModel::LogModel(const LogModelConfig& config, LogRowColorizer* rowColorizer)
    : mConfig(config), mRowColorizer(rowColorizer) {}

LogModel::~LogModel() { delete mRowColorizer; }

int LogModel::columnCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return mConfig.headers().size();
}

QVariant LogModel::headerData(int section, Qt::Orientation orientation,
                              int role) const {
  if (role == Qt::DisplayRole) {
    if (orientation == Qt::Horizontal) {
      if (section < mConfig.headers().size()) {
        return mConfig.headers()[section];
      }
    } else {
      return QVariant(section + 1);
    }
  }
  return QVariant();
}

int LogModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return mEntries.size();
}

QVariant LogModel::data(const QModelIndex& index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  if (role == MultiLineRole) {
    QString columnHeader = mConfig.headers()[index.column()];
    return mEntries[index.row()].isPartMultiline(columnHeader);
  }
  if (role == Qt::CheckStateRole &&
      mConfig.headers()[index.column()] == "IS_MULTILINE") {
    return QVariant(mEntries[index.row()].isPartMultiline("CONTENT")
                        ? Qt::Checked
                        : Qt::Unchecked);
  } else if (role == Qt::DisplayRole || role == Qt::ToolTipRole) {
    QString columnHeader = mConfig.headers()[index.column()];
    return mEntries[index.row()].getPart(columnHeader);
  } else if (role == Qt::BackgroundRole) {
    if (mRowColorizer != nullptr) {
      return mRowColorizer->getBrushForEntry(mEntries[index.row()]);
    }
  }
  return QVariant();
}

Qt::ItemFlags LogModel::flags(const QModelIndex& index) const {
  if (mConfig.headers()[index.column()] == "HAS_ADDITIONAL_DATA") {
    return QAbstractTableModel::flags(index) | Qt::ItemIsUserCheckable;
  }
  return QAbstractTableModel::flags(index);
}

void LogModel::addRow(const LogEntry& entry) {
  emit beginInsertRows(QModelIndex(), mEntries.size(), mEntries.size());
  mEntries.append(entry);
  emit endInsertRows();
  if (mConfig.limitRows() != -1 && mEntries.size() > mConfig.limitRows()) {
    int tenPercentOfLimit = mConfig.limitRows() / 10;
    emit beginRemoveRows(QModelIndex(), 0, tenPercentOfLimit - 1);
    mEntries.remove(0, tenPercentOfLimit);
    emit endRemoveRows();
  }
}

void LogModel::mergeLastRow(const LogEntry& entry) {
  mEntries.last().merge(entry);
  emit dataChanged(index(mEntries.size(), 0),
                   index(mEntries.size(), mConfig.headers().size()));
}
