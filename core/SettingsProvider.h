#ifndef SETTINGSPROVIDER_H
#define SETTINGSPROVIDER_H

#include "LoggerObjectSettings.h"

#include <core_export.h>
#include <QList>
#include <QSettings>

#include <QJsonDocument>
class CORE_EXPORT SettingsProvider {
 public:
  SettingsProvider();

  QJsonDocument getJsonSettings() const;
  bool trySaveSettings(const QString& settingsString, QString& errorString,
                       bool ignoreEmpty = false);
  QVariant getSettingsFor(const QString& name);

 private:
  QMap<QString, QVariant> mSettings;
  //	QVariant mSettings;
};

#endif  // SETTINGSPROVIDER_H
