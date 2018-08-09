#include <LogModelConfig.h>
#include <QtTest/QtTest>

class LogModelConfigSerializationTest : public QObject {
  Q_OBJECT
 private slots:
  void serialize();
  void unserialize();
};

void LogModelConfigSerializationTest::serialize() {
  static const QString expectedResult(
      R"({
    "headers": [
        "HEADER_1",
        "HEADER_2",
        "HEADER_3"
    ],
    "limitRows": 125
}
)");
  LogModelConfig config;
  config.setLimitRows(125);
  config.setHeaders(QStringList() << "HEADER_1"
                                  << "HEADER_2"
                                  << "HEADER_3");

  QJsonObject json;
  config.write(json);
  QJsonDocument document;
  document.setObject(json);

  QCOMPARE(QString(document.toJson()), expectedResult);
}

void LogModelConfigSerializationTest::unserialize() {
  static const QString input(
      R"({
    "headers": [
        "HEADER_1",
        "HEADER_2",
        "HEADER_3"
    ],
    "limitRows": 125
}
)");

  LogModelConfig config;

  QJsonDocument document = QJsonDocument::fromJson(input.toLocal8Bit());

  auto json = document.object();
  config.read(json);

  QCOMPARE(config.headers(), QStringList() << "HEADER_1"
                                           << "HEADER_2"
                                           << "HEADER_3");
  QCOMPARE(config.limitRows(), 125);
}

QTEST_APPLESS_MAIN(LogModelConfigSerializationTest)

#include "LogModelConfigSerializationTest.moc"
