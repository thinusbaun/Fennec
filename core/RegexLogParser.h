#ifndef REGEXLOGPARSER_H
#define REGEXLOGPARSER_H

#include <core_export.h>
#include <QObject>
#include <QRegularExpression>
#include "LogParser.h"

class CORE_EXPORT RegexLogParser : public LogParser {
  Q_OBJECT
 public:
  explicit RegexLogParser(const QString &regex, QObject *parent = nullptr);

 public slots:
  virtual void parseLine(QString line);

 private:
  QRegularExpression mRegExp;
};

#endif  // REGEXLOGPARSER_H
