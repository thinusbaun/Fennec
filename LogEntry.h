#ifndef LOGENTRY_H
#define LOGENTRY_H
#include <QString>
#include <QDateTime>
#include <QDebug>

class LogEntry
{
public:
  LogEntry();

  void setPart(const QString& name, const QVariant& value);
  QVariant getPart(const QString& name) const;
  const QMap<QString, QVariant> getPartsMap() const;
  bool isPartMultiline(const QString& part) const;
  void merge(const LogEntry& entry);
private:
  QMap<QString, QVariant> mPartsMap;
  QMap<QString, bool> mMultilinesMap;
};


#endif // LOGENTRY_H
