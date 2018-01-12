
#include "LogEntryTest.h"

void LogEntryTest::setPart() {
  LogEntry entry;
  entry.setPart("PART_NAME", QVariant("PART_VALUE"));
  QVERIFY2(entry.getPartsMap().contains("PART_NAME"),
           "Log entry does not contain part.");
  QCOMPARE("PART_VALUE", entry.getPartsMap()["PART_NAME"]);
}

void LogEntryTest::mergeString() {
  LogEntry first, second;

  first.setPart("PART_NAME", QVariant("first_line"));
  second.setPart("PART_NAME", QVariant("second_line"));

  first.merge(second);
  QCOMPARE("first_line\nsecond_line", first.getPartsMap()["PART_NAME"]);
}

void LogEntryTest::mergeNonString() {
  LogEntry first, second;

  first.setPart("PART_NAME", 123);
  second.setPart("PART_NAME", 456);

  first.merge(second);
  QVERIFY(first.getPartsMap()["PART_NAME"].type() != QVariant::String);
  QCOMPARE(first.getPartsMap()["PART_NAME"], 123);
}
