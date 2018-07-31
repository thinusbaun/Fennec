#include <IdentifiableObject.h>
#include <ObjectContentHandler.hh>
#include <QtTest/QtTest>

class IdentifiableObjectSerializationTest : public QObject {
  Q_OBJECT
 private slots:
  void serialize();
  void unserialize();
};

void IdentifiableObjectSerializationTest::serialize() {
  IdentifiableObject object;
  object.setId(123);
  object.setName("TEST NAME");
  ObjectContentHandler<IdentifiableObject> handler;
  auto json = handler.toJsonObject(&object);
  QJsonObject expectedOutput =
      QJsonObject({{"id", 123}, {"name", "TEST NAME"}});
  QCOMPARE(QString(QJsonDocument(json).toJson()),
           QString(QJsonDocument(expectedOutput).toJson()));
}

void IdentifiableObjectSerializationTest::unserialize() {
  ObjectContentHandler<IdentifiableObject> handler;
  QJsonObject input = QJsonObject({{"id", 123}, {"name", "TEST NAME"}});

  auto obj = handler.toObject(input);
  QTEST_ASSERT(obj != nullptr);
  QCOMPARE(obj->id(), 123UL);
  QCOMPARE(obj->name(), QString("TEST NAME"));
}

QTEST_APPLESS_MAIN(IdentifiableObjectSerializationTest)

#include "IdentifiableObjectSerializationTest.moc"
