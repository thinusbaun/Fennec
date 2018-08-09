#ifndef LOGMODELCONFIG_H
#define LOGMODELCONFIG_H

#include <QJsonObject>
#include <QStringList>

#include "core_export.h"

class CORE_EXPORT LogModelConfig {
 public:
  LogModelConfig();

  void read(const QJsonObject& json);
  void write(QJsonObject& json) const;

  QStringList headers() const;
  void setHeaders(const QStringList& headers);

  int limitRows() const;
  void setLimitRows(int limitRows);

 private:
  QStringList mHeaders;
  int mLimitRows = -1;
};

#endif  // LOGMODELCONFIG_H
