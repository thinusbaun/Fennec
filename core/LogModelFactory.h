#ifndef LOGMODELFACTORY_H
#define LOGMODELFACTORY_H

#include <core_export.h>
#include <QMap>
#include <QObject>

class LogModel;
class SettingsProvider;

class CORE_EXPORT LogModelFactory : public QObject {
  Q_OBJECT
 public:
  explicit LogModelFactory(SettingsProvider &mSettingsProvider,
                           QObject *parent = nullptr);
  virtual ~LogModelFactory();

  LogModel *create();

 private:
  SettingsProvider &mSettingsProvider;
};

#endif  // LOGMODELFACTORY_H
