#include <TailFileWatchConfig.h>
#include <QtTest/QtTest>

class TailFileWatchConfigSerializationTest : public QObject {
  Q_OBJECT
 private slots:
  void serialize();
  void unserialize();
  void serializeEmpty();
  void unserializeEmpty();
};

void TailFileWatchConfigSerializationTest::serialize() {
  static const QString expectedResult(
      R"({
    "args": [
        "-param1",
        "-param2",
        "param2_value"
    ],
    "exec_path": "Process_path"
}
)");
  TailFileWatchConfig config;
  config.setProcessPath("Process_path");
  config.setArgs(QStringList() << "-param1"
                               << "-param2"
                               << "param2_value");

  QJsonObject json;
  config.write(json);
  QJsonDocument document;
  document.setObject(json);

  QCOMPARE(QString(document.toJson()), expectedResult);
}

void TailFileWatchConfigSerializationTest::unserialize() {
  static const QString input(
      R"({
    "args": [
        "-param1",
        "-param2",
        "param2_value"
    ],
    "exec_path": "Process_path"
}
)");
  TailFileWatchConfig config;

  QJsonDocument document = QJsonDocument::fromJson(input.toLocal8Bit());

  auto json = document.object();
  config.read(json);

  QCOMPARE(config.args(), QStringList() << "-param1"
                                        << "-param2"
                                        << "param2_value");
  QCOMPARE(config.processPath(), QString("Process_path"));
}

void TailFileWatchConfigSerializationTest::serializeEmpty() {
  static const QString expectedResult(
      R"({
}
)");
  TailFileWatchConfig config;

  QJsonObject json;
  config.write(json);
  QJsonDocument document;
  document.setObject(json);

  QCOMPARE(QString(document.toJson()), expectedResult);
}

void TailFileWatchConfigSerializationTest::unserializeEmpty() {
  static const QString input(
      R"({
}
)");
  TailFileWatchConfig config;

  QJsonDocument document = QJsonDocument::fromJson(input.toLocal8Bit());

  auto json = document.object();
  config.read(json);

  QCOMPARE(config.args(), QStringList());
  QCOMPARE(config.processPath(), QString());
}

QTEST_APPLESS_MAIN(TailFileWatchConfigSerializationTest)

#include "TailFileWatchConfigSerializationTest.moc"
