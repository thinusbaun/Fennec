#ifndef TAILFILEWATCHCONFIG_H
#define TAILFILEWATCHCONFIG_H

#include <QJsonObject>
#include <QString>
#include <QStringList>

#include "core_export.h"

class CORE_EXPORT TailFileWatchConfig {
 public:
  TailFileWatchConfig();

  void read(const QJsonObject& json);
  void write(QJsonObject& json) const;

  QString processPath() const;
  void setProcessPath(const QString& processPath);

  QStringList args() const;
  void setArgs(const QStringList& args);

 private:
  QString mProcessPath;
  QStringList mArgs;
};

#endif  // TAILFILEWATCHCONFIG_H
