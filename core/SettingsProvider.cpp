#include "SettingsProvider.h"

SettingsProvider::SettingsProvider() {}

std::pair<bool, QString> SettingsProvider::loadSettings(
    const QByteArray& input) {
  QJsonParseError error;
  auto document = QJsonDocument::fromJson(input, &error);
  if (error.error != QJsonParseError::NoError) {
    return {false, error.errorString()};
  }
  if (!document.isObject()) {
    return {false, "No object found in input"};
  }
  auto jsonObject = document.object();
  mContainer = SettingsContainer();
  mContainer.read(jsonObject);

  return {true, QString()};
}

QByteArray SettingsProvider::saveSettings() {
  QJsonObject jsonObject;
  mContainer.write(jsonObject);
  QJsonDocument document = QJsonDocument(jsonObject);
  return document.toJson();
}

QVariant SettingsProvider::getSettingsFor(const QString& name) {
  if (mSettings.contains(name)) {
    return mSettings[name];
  } else {
    return QMap<QString, QVariant>();
  }
}
