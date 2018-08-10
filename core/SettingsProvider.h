#ifndef SETTINGSPROVIDER_H
#define SETTINGSPROVIDER_H

#include "LoggerObjectSettings.h"
#include "SettingsContainer.h"

#include <core_export.h>
#include <QList>
#include <QSettings>

#include <QJsonDocument>

class CORE_EXPORT SettingsProvider {
 public:
  SettingsProvider();

  std::pair<bool, QString> loadSettings(const QByteArray& input);
  QByteArray saveSettings();

  QVariant getSettingsFor(const QString& name);

  SettingsContainer getContainer() const;

 private:
  SettingsContainer mContainer;
  QMap<QString, QVariant> mSettings;
};

#endif  // SETTINGSPROVIDER_H
