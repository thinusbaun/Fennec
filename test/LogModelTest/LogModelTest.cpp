#include <LogEntry.h>
#include <LogModel.h>
#include <QSignalSpy>
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

void LogModelTest::setColumnsCount() {
  QStringList columns{"A", "B", "C", "D"};
  LogModel model(columns);
  QCOMPARE(model.columnCount(model.index(0, 0)), columns.size());
}

void LogModelTest::addRow() {
  QStringList columns{"A", "B", "C", "D"};
  LogModel model(columns);
  QSignalSpy beginInsertSpy(&model, &LogModel::rowsAboutToBeInserted);
  QSignalSpy endInsertSpy(&model, &LogModel::rowsInserted);
  LogEntry entry;
  for (auto& it : columns) {
    entry.setPart(it, it);
  }
  model.addRow(entry);

  QCOMPARE(beginInsertSpy.count(), 1);
  QCOMPARE(endInsertSpy.count(), 1);
  QCOMPARE(model.rowCount(model.index(0, 0)), 1);
}

void LogModelTest::mergeRow() {
  QStringList columns{"A", "B", "C", "D"};
  LogModel model(columns);
  QSignalSpy dataChangedSpy(&model, &LogModel::dataChanged);
  LogEntry entry;
  for (auto& it : columns) {
    entry.setPart(it, it);
  }
  model.addRow(entry);
  LogEntry entryCopy(entry);
  model.mergeLastRow(entryCopy);

  QCOMPARE(dataChangedSpy.count(), 1);
  QCOMPARE(model.rowCount(model.index(0, 0)), 1);
}

void LogModelTest::headerData() {
  QStringList columns{"A", "B", "C", "D"};
  LogModel model(columns);
  LogEntry entry;
  for (auto& it : columns) {
    entry.setPart(it, it);
  }
  model.addRow(entry);

  QCOMPARE(model.headerData(0, Qt::Horizontal, Qt::DisplayRole).toString(),
           columns[0]);
  QCOMPARE(model.headerData(0, Qt::Vertical, Qt::DisplayRole).toInt(), 1);
  QVERIFY(!model.headerData(columns.size() + 2, Qt::Horizontal, Qt::DisplayRole)
               .isValid());
}

void LogModelTest::dataDisplayAndToolTipRole() {
  QStringList columns{"A", "B", "C", "D"};
  LogModel model(columns);
  LogEntry entry;
  for (auto& it : columns) {
    entry.setPart(it, it);
  }
  model.addRow(entry);

  QCOMPARE(model.data(model.index(0, 0), Qt::DisplayRole).toString(),
           columns[0]);
  QCOMPARE(model.data(model.index(0, 0), Qt::ToolTipRole).toString(),
           columns[0]);
  QVERIFY(!model.data(model.index(1, 1), Qt::DisplayRole).isValid());
}

void LogModelTest::dataMultilineRole() {
  QStringList columns{"A", "B", "C", "D"};
  LogModel model(columns);
  LogEntry entry;
  for (auto& it : columns) {
    entry.setPart(it, it);
  }
  LogEntry entryCopy(entry);
  entry.merge(entryCopy);
  model.addRow(entry);

  QCOMPARE(model.data(model.index(0, 0), LogModel::MultiLineRole).toBool(),
           true);
  QVERIFY(!model.data(model.index(1, 1), LogModel::MultiLineRole).isValid());
}

QTEST_APPLESS_MAIN(LogModelTest)

#include "LogModelTest.moc"
