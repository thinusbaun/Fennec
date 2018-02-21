#ifndef SETTINGSPROVIDER_H
#define SETTINGSPROVIDER_H

#include "LoggerObjectSettings.h"

#include <QList>
#include <QSettings>
#include <core_export.h>

class CORE_EXPORT SettingsProvider {
public:
  SettingsProvider(QSettings *settings);

  QList<LoggerObjectSettings> getAllLoggersSettings();

private:
  QSettings *mSettings;
};

#endif // SETTINGSPROVIDER_H
