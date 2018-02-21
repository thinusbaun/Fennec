#ifndef LOGMODEL_H
#define LOGMODEL_H

#include <LogEntry.h>
#include <QAbstractTableModel>
#include <core_export.h>

class CORE_EXPORT LogModel : public QAbstractTableModel {
  Q_OBJECT
public:
  constexpr static int MultiLineRole = Qt::UserRole + 1;

  LogModel(const QStringList &headers);
  int columnCount(const QModelIndex &parent) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  int rowCount(const QModelIndex &parent) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  Qt::ItemFlags flags(const QModelIndex &index) const;

public slots:
  void addRow(const LogEntry &entry);
  void mergeLastRow(const LogEntry &entry);

private:
  QStringList mHeaders;
  QVector<LogEntry> mEntries;
};

#endif // LOGMODEL_H
