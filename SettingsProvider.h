#ifndef SETTINGSPROVIDER_H
#define SETTINGSPROVIDER_H

#include "LoggerObjectSettings.h"

#include <QList>
#include <QSettings>

class SettingsProvider
{
public:
    SettingsProvider(QSettings *settings);

    QList<LoggerObjectSettings> getAllLoggersSettings();
private:
    QSettings *mSettings;
};

#endif // SETTINGSPROVIDER_H
