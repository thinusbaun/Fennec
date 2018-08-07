#include "SettingsContainer.h"

SettingsContainer::SettingsContainer() {}

void SettingsContainer::read(const QJsonObject &json) {
  mFileWatchConfig.read(json["fileWatch"].toObject());
  mLogParserConfig.read(json["logParser"].toObject());
  mName = json["name"].toString();
  mSourcePath = json["sourcePath"].toString();
}

void SettingsContainer::write(QJsonObject &json) const {
  {
    QJsonObject jsonObject;
    mFileWatchConfig.write(jsonObject);
    json["fileWatch"] = jsonObject;
  }
  {
    QJsonObject jsonObject;
    mLogParserConfig.write(jsonObject);
    json["logParser"] = jsonObject;
  }

  json["name"] = mName;
  json["sourcePath"] = mSourcePath;
}

QString SettingsContainer::sourcePath() const { return mSourcePath; }

void SettingsContainer::setSourcePath(const QString &sourcePath) {
  mSourcePath = sourcePath;
}

QString SettingsContainer::name() const { return mName; }

void SettingsContainer::setName(const QString &name) { mName = name; }

TailFileWatchConfig SettingsContainer::fileWatchConfig() const {
  return mFileWatchConfig;
}

void SettingsContainer::setFileWatchConfig(
    const TailFileWatchConfig &fileWatchConfig) {
  mFileWatchConfig = fileWatchConfig;
}

RegexLogParserConfig SettingsContainer::logParserConfig() const {
  return mLogParserConfig;
}

void SettingsContainer::setLogParserConfig(
    const RegexLogParserConfig &logParserConfig) {
  mLogParserConfig = logParserConfig;
}