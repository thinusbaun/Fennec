#ifndef LOGENTRYTEST_H
#define LOGENTRYTEST_H
#include <LogEntry.h>
#include <QtTest/QtTest>

class LogEntryTest : public QObject {
  Q_OBJECT
private slots:
  void setPart();
  void mergeString();
  void mergeNonString();
};
#endif // LOGENTRYTEST_H
