#ifndef SETTINGSPROVIDER_H
#define SETTINGSPROVIDER_H

#include "LoggerObjectSettings.h"

#include <QList>
#include <QSettings>
#include <core_export.h>

#include <QJsonDocument>
class CORE_EXPORT SettingsProvider {
public:
  SettingsProvider();

  QJsonDocument getJsonSettings() const;
  bool trySaveSettings(const QString & settingsString, QString & errorString);

private:
	QVariant mSettings;
};

#endif // SETTINGSPROVIDER_H
