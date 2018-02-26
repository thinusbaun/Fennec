#include "SettingsProvider.h"

SettingsProvider::SettingsProvider() {}

QJsonDocument SettingsProvider::getJsonSettings() const {
  return QJsonDocument::fromVariant(mSettings);
}

bool SettingsProvider::trySaveSettings(const QString& settingsString,
                                       QString& errorString, bool ignoreEmpty) {
  if (settingsString.isEmpty() && !ignoreEmpty) {
    errorString = "Settings string is empty.";
    return false;
  }
  QJsonParseError error;
  auto document = QJsonDocument::fromJson(settingsString.toUtf8(), &error);
  if (error.error != QJsonParseError::NoError) {
    errorString = error.errorString();
    return false;
  }
  mSettings = document.toVariant();
  return true;
}
