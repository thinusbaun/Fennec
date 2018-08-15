#include "SettingsProvider.h"
#include <QJsonArray>

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
  auto jsonArray = document.array();
  mContainer.reserve(jsonArray.size());
  for (const auto& it : jsonArray) {
    SingleLogSetting setting;
    setting.read(it.toObject());
    mContainer.push_back(setting);
  }

  return {true, QString()};
}

QByteArray SettingsProvider::saveSettings() {
  QJsonArray jsonArray;
  for (const auto& it : mContainer) {
    QJsonObject object;
    it.write(object);
    jsonArray.push_back(object);
  }
  QJsonDocument document = QJsonDocument(jsonArray);
  return document.toJson();
}

SettingsProvider::SettingsIterT SettingsProvider::begin() {
  return mContainer.begin();
}

SettingsProvider::SettingsIterT SettingsProvider::end() {
  return mContainer.end();
}
