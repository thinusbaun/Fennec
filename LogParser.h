#ifndef LOGPARSER_H
#define LOGPARSER_H

#include <QObject>
#include <LogEntry.h>

class LogParser
  : public QObject
{
  Q_OBJECT
public:
  explicit LogParser(QObject* parent = nullptr);

signals:

   void lineParsed(LogEntry);
   void multiLineParsed(LogEntry);

public slots:
  virtual void parseLine(QString line) = 0;
};

#endif // LOGPARSER_H
