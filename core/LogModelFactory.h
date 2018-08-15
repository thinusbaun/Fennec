#ifndef LOGMODELFACTORY_H
#define LOGMODELFACTORY_H

#include <core_export.h>
#include <QMap>
#include <QObject>

class LogModel;
class SingleLogSetting;

class CORE_EXPORT LogModelFactory : public QObject {
  Q_OBJECT
 public:
  explicit LogModelFactory(const SingleLogSetting &settings,
                           QObject *parent = nullptr);
  virtual ~LogModelFactory();

  LogModel *create();

 private:
  const SingleLogSetting &mSettings;
};

#endif  // LOGMODELFACTORY_H
