#ifndef SETTINGSPROVIDER_H
#define SETTINGSPROVIDER_H

#include "LoggerObjectSettings.h"
#include "SingleLogSetting.h"

#include <core_export.h>
#include <QSettings>
#include <QVector>

#include <QJsonDocument>

class CORE_EXPORT SettingsProvider {
  using SettingsIterT = QVector<SingleLogSetting>::const_iterator;

 public:
  SettingsProvider();

  std::pair<bool, QString> loadSettings(const QByteArray& input);
  QByteArray saveSettings();

  SettingsIterT begin();
  SettingsIterT end();

 private:
  QVector<SingleLogSetting> mContainer;
};

#endif  // SETTINGSPROVIDER_H
