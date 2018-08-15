#include "SingleLogSetting.h"

SingleLogSetting::SingleLogSetting() {}

void SingleLogSetting::read(const QJsonObject &json) {
  mFileWatchConfig.read(json["fileWatch"].toObject());
  mLogParserConfig.read(json["logParser"].toObject());
  mLogModelConfig.read(json["logModel"].toObject());
  mLogRowColorizerConfig.read(json["logRowColorizer"].toObject());
  mName = json["name"].toString();
  mSourcePath = json["sourcePath"].toString();
}

void SingleLogSetting::write(QJsonObject &json) const {
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
  {
    QJsonObject jsonObject;
    mLogModelConfig.write(jsonObject);
    json["logModel"] = jsonObject;
  }
  {
    QJsonObject jsonObject;
    mLogRowColorizerConfig.write(jsonObject);
    json["logRowColorizer"] = jsonObject;
  }
  json["name"] = mName;
  json["sourcePath"] = mSourcePath;
}

QString SingleLogSetting::sourcePath() const { return mSourcePath; }

void SingleLogSetting::setSourcePath(const QString &sourcePath) {
  mSourcePath = sourcePath;
}

QString SingleLogSetting::name() const { return mName; }

void SingleLogSetting::setName(const QString &name) { mName = name; }

TailFileWatchConfig SingleLogSetting::fileWatchConfig() const {
  return mFileWatchConfig;
}

void SingleLogSetting::setFileWatchConfig(
    const TailFileWatchConfig &fileWatchConfig) {
  mFileWatchConfig = fileWatchConfig;
}

RegexLogParserConfig SingleLogSetting::logParserConfig() const {
  return mLogParserConfig;
}

void SingleLogSetting::setLogParserConfig(
    const RegexLogParserConfig &logParserConfig) {
  mLogParserConfig = logParserConfig;
}

LogModelConfig SingleLogSetting::logModelConfig() const {
  return mLogModelConfig;
}

void SingleLogSetting::setLogModelConfig(const LogModelConfig &logModelConfig) {
  mLogModelConfig = logModelConfig;
}

LogRowColorizerConfig SingleLogSetting::logRowColorizerConfig() const {
  return mLogRowColorizerConfig;
}

void SingleLogSetting::setLogRowColorizerConfig(
    const LogRowColorizerConfig &logRowColorizerConfig) {
  mLogRowColorizerConfig = logRowColorizerConfig;
}
