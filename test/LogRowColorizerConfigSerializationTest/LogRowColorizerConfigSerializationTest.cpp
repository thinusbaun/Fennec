#include <LogRowColorizerConfig.h>
#include <QtTest/QtTest>

class LogRowColorizerConfigSerializationTest : public QObject {
  Q_OBJECT
 private slots:
  void serialize();
  void unserialize();
};

void LogRowColorizerConfigSerializationTest::serialize() {
  static const QString expectedResult(
      R"({
    "partName": "Part Name Test",
    "values": [
        {
            "color": "#ff0000",
            "match": "value1"
        }
    ]
}
)");
  LogRowColorizerConfig config;
  config.setPartName("Part Name Test");
  config.addColorForValue("value1", QColor(Qt::red));

  QJsonObject json;
  config.write(json);
  QJsonDocument document;
  document.setObject(json);

  QCOMPARE(expectedResult, QString(document.toJson()));
}

void LogRowColorizerConfigSerializationTest::unserialize() {
  static const QString input(
      R"({
    "partName": "Part Name Test",
    "values": [
        {
            "color": "#ff0000",
            "match": "value1"
        }
    ]
}
)");
  LogRowColorizerConfig config;

  QJsonDocument document = QJsonDocument::fromJson(input.toLocal8Bit());

  auto json = document.object();
  config.read(json);

  QCOMPARE(config.partName(), QString("Part Name Test"));
  QCOMPARE(config.getColorForValue("value1").name(), QColor(Qt::red).name());
}

QTEST_APPLESS_MAIN(LogRowColorizerConfigSerializationTest)

#include "LogRowColorizerConfigSerializationTest.moc"
