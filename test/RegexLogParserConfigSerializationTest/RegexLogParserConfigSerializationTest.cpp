#include <RegexLogParserConfig.h>
#include <QtTest/QtTest>

class RegexLogParserConfigSerializationTest : public QObject {
  Q_OBJECT
 private slots:
  void serialize();
  void unserialize();
};

void RegexLogParserConfigSerializationTest::serialize() {
  static const QString expectedResult(
      R"({
    "regex": "^\\d\\w$"
}
)");
  RegexLogParserConfig config;
  config.setRegex(R"(^\d\w$)");

  QJsonObject json;
  config.write(json);
  QJsonDocument document;
  document.setObject(json);

  QCOMPARE(QString(document.toJson()), expectedResult);
}

void RegexLogParserConfigSerializationTest::unserialize() {
  static const QString input(
      R"({
    "regex": "^\\d\\w$"
}
)");
  RegexLogParserConfig config;

  QJsonDocument document = QJsonDocument::fromJson(input.toLocal8Bit());

  auto json = document.object();
  config.read(json);

  QCOMPARE(config.regex(), QString(R"(^\d\w$)"));
}

QTEST_APPLESS_MAIN(RegexLogParserConfigSerializationTest)

#include "RegexLogParserConfigSerializationTest.moc"
