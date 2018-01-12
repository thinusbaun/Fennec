#ifndef LOGMODELTEST_H
#define LOGMODELTEST_H

#include <LogEntry.h>
#include <QtTest/QtTest>

class LogModelTest : public QObject {
  Q_OBJECT
private slots:
  void setColumnsCount();
  void addRow();
  void mergeRow();
  void headerData();
  void dataDisplayAndToolTipRole();
  void dataMultilineRole();
};

#endif // LOGMODELTEST_H
