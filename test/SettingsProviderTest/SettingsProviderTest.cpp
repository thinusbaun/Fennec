#include <SettingsProvider.h>
#include <QString>
#include <QtTest>

class SettingsProviderTest : public QObject {
  Q_OBJECT

 public:
  SettingsProviderTest();

 private Q_SLOTS:
  void goodLoadTest();
  void badLoadTest();
};

SettingsProviderTest::SettingsProviderTest() {}

void SettingsProviderTest::goodLoadTest() {
  QString input = "{}";
  SettingsProvider provider;
  auto result = provider.loadSettings(input.toUtf8());
  QTEST_ASSERT(result.first);
  QCOMPARE(result.second, QString());
}

void SettingsProviderTest::badLoadTest() {
  QString input = "{999}";
  SettingsProvider provider;
  auto result = provider.loadSettings(input.toUtf8());
  QCOMPARE(result.first, false);
  qDebug() << result.second;
  QCOMPARE(result.second.isEmpty(), false);
}

QTEST_APPLESS_MAIN(SettingsProviderTest)

#include "SettingsProviderTest.moc"
