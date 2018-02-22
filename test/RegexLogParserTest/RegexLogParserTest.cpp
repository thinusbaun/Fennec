#include <LogEntry.h>
#include <RegexLogParser.h>
#include <QString>
#include <QtTest>
#include <memory>

class RegexLogParserTest : public QObject {
  Q_OBJECT

 public:
  RegexLogParserTest();

 private Q_SLOTS:
  void simpleParseTest();
  void mergeParseTest();
};

RegexLogParserTest::RegexLogParserTest() {}

void RegexLogParserTest::simpleParseTest() {
  std::unique_ptr<RegexLogParser> parser(new RegexLogParser(QString(
      R"((?<day>\d\d)-(?<month>\d\d)-(?<year>\d\d\d\d) (?<something>\w+) (?<name>\w+))")));
  qRegisterMetaType<LogEntry>();
  QSignalSpy parseLineSpy(parser.get(), &RegexLogParser::lineParsed);
  QString line = "12-12-2018 Something Name";
  parser->parseLine(line);
  QVERIFY(parseLineSpy.count() == 1);
  LogEntry parsedEntry = qvariant_cast<LogEntry>(parseLineSpy.at(0).at(0));
  QCOMPARE(parsedEntry.getPartsMap().size(), 5);
}

void RegexLogParserTest::mergeParseTest() {
  std::unique_ptr<RegexLogParser> parser(new RegexLogParser(QString(
      R"((?<day>\d\d)-(?<month>\d\d)-(?<year>\d\d\d\d) (?<something>\w+) (?<name>\w+))")));
  qRegisterMetaType<LogEntry>();
  QSignalSpy parseLineSpy(parser.get(), &RegexLogParser::multiLineParsed);
  QString line = "SOMETHING ADDITIONAL";
  parser->parseLine(line);
  QVERIFY(parseLineSpy.count() == 1);
  LogEntry parsedEntry = qvariant_cast<LogEntry>(parseLineSpy.at(0).at(0));
  QCOMPARE(parsedEntry.getPartsMap().size(), 1);
  QCOMPARE(parsedEntry.getPart("name").toString(), line);
}

QTEST_APPLESS_MAIN(RegexLogParserTest)

#include "RegexLogParserTest.moc"
