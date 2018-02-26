#ifndef LOGMODEL_H
#define LOGMODEL_H

#include <LogEntry.h>
#include <core_export.h>
#include <QAbstractTableModel>

class LogRowColorizer;

class CORE_EXPORT LogModel : public QAbstractTableModel {
  Q_OBJECT
 public:
  constexpr static int MultiLineRole = Qt::UserRole + 1;

  LogModel(const QStringList &headers, LogRowColorizer *rowColorizer);
  ~LogModel();
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
  LogRowColorizer *mRowColorizer;
};

#endif  // LOGMODEL_H
