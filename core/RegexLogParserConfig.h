#ifndef REGEXLOGPARSERCONFIG_H
#define REGEXLOGPARSERCONFIG_H

#include <QJsonObject>

#include "core_export.h"

class CORE_EXPORT RegexLogParserConfig {
 public:
  RegexLogParserConfig();

  void read(const QJsonObject& json);
  void write(QJsonObject& json) const;

  QString regex() const;
  void setRegex(const QString& regex);

 private:
  QString mRegex;
};

#endif  // REGEXLOGPARSERCONFIG_H
