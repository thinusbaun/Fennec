#ifndef LOGMODELFACTORY_H
#define LOGMODELFACTORY_H

#include <QMap>
#include <QObject>
#include <core_export.h>

class LogModel;

class CORE_EXPORT LogModelFactory : public QObject {
  Q_OBJECT
public:
  explicit LogModelFactory(const QMap<QString, QVariant> &settings,
                           QObject *parent = nullptr);
  virtual ~LogModelFactory();

  LogModel *create();

private:
  const QMap<QString, QVariant> mSettings;
};

#endif // LOGMODELFACTORY_H
