#ifndef TAILFILEWATCHFACTORY_H
#define TAILFILEWATCHFACTORY_H

#include <core_export.h>
#include <QMap>
#include <QObject>
#include <QString>
#include <QVariant>
#include "SingleLogSetting.h"

class TailFileWatch;

class CORE_EXPORT TailFileWatchFactory : public QObject {
  Q_OBJECT
 public:
  TailFileWatchFactory(const SingleLogSetting &settings,
                       QObject *parent = nullptr);

  TailFileWatch *create();

 private:
  const SingleLogSetting &mSettings;
};

#endif  // TAILFILEWATCHFACTORY_H
