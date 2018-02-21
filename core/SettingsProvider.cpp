#include "SettingsProvider.h"

SettingsProvider::SettingsProvider(QSettings* settings) : mSettings(settings) {}

QList<LoggerObjectSettings> SettingsProvider::getAllLoggersSettings() {
  QList<LoggerObjectSettings> result;
  mSettings->beginGroup("LOGGERS");
  for (auto& x : mSettings->childGroups()) {
    mSettings->beginGroup(x);
    LoggerObjectSettings loggerSettings;
    loggerSettings.setName(mSettings->value("name").toString());
    loggerSettings.setHeaders(mSettings->value("headers").toStringList());
    loggerSettings.setLogParserName(mSettings->value("parserName").toString());
    loggerSettings.setLogWatchName(mSettings->value("watchName").toString());
    loggerSettings.setFilePath(mSettings->value("filePath").toString());
    mSettings->endGroup();
    result.append(loggerSettings);
  }
  return result;
}
