#ifndef TAILFILEWATCHFACTORY_H
#define TAILFILEWATCHFACTORY_H

#include <core_export.h>
#include <QMap>
#include <QObject>
#include <QString>
#include <QVariant>
#include "SettingsProvider.h"

class TailFileWatch;

class CORE_EXPORT TailFileWatchFactory : public QObject {
  Q_OBJECT
 public:
  TailFileWatchFactory(SettingsProvider &settingsProvider,
                       QObject *parent = nullptr);

  TailFileWatch *create();

 private:
  SettingsProvider &mSettingsProvider;
};

#endif  // TAILFILEWATCHFACTORY_H
