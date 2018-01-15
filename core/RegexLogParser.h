#ifndef REGEXLOGPARSER_H
#define REGEXLOGPARSER_H

#include "LogParser.h"
#include <QObject>
#include <QRegularExpression>

class RegexLogParser : public LogParser {
  Q_OBJECT
public:
  explicit RegexLogParser(const QString &regex, QObject *parent = nullptr);

public slots:
  virtual void parseLine(QString line);

private:
  QRegularExpression mRegExp;
};

#endif // REGEXLOGPARSER_H
