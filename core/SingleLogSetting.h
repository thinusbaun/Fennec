#ifndef SETTINGSCONTAINER_H
#define SETTINGSCONTAINER_H

#include "LogModelConfig.h"
#include "LogRowColorizerConfig.h"
#include "RegexLogParserConfig.h"
#include "TailFileWatchConfig.h"

#include <QJsonObject>

class SingleLogSetting {
 public:
  SingleLogSetting();

  void read(const QJsonObject &json);
  void write(QJsonObject &json) const;

  QString sourcePath() const;
  void setSourcePath(const QString &sourcePath);

  QString name() const;
  void setName(const QString &name);

  TailFileWatchConfig fileWatchConfig() const;
  void setFileWatchConfig(const TailFileWatchConfig &fileWatchConfig);

  RegexLogParserConfig logParserConfig() const;
  void setLogParserConfig(const RegexLogParserConfig &logParserConfig);

  LogModelConfig logModelConfig() const;
  void setLogModelConfig(const LogModelConfig &logModelConfig);

  LogRowColorizerConfig logRowColorizerConfig() const;
  void setLogRowColorizerConfig(
      const LogRowColorizerConfig &logRowColorizerConfig);

 private:
  TailFileWatchConfig mFileWatchConfig;
  RegexLogParserConfig mLogParserConfig;
  LogModelConfig mLogModelConfig;
  LogRowColorizerConfig mLogRowColorizerConfig;
  QString mSourcePath;
  QString mName;
};

#endif  // SETTINGSCONTAINER_H