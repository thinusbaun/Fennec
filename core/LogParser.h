#ifndef LOGPARSER_H
#define LOGPARSER_H

#include <LogEntry.h>
#include <QObject>
#include <core_export.h>

class CORE_EXPORT LogParser : public QObject {
  Q_OBJECT
public:
  explicit LogParser(QObject *parent = nullptr);

signals:

  void lineParsed(LogEntry);
  void multiLineParsed(LogEntry);

public slots:
  virtual void parseLine(QString line) = 0;
};

#endif // LOGPARSER_H
