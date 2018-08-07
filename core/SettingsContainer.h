#ifndef SETTINGSCONTAINER_H
#define SETTINGSCONTAINER_H

#include "RegexLogParserConfig.h"
#include "TailFileWatchConfig.h"

#include <QJsonObject>

class SettingsContainer {
 public:
  SettingsContainer();

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

 private:
  TailFileWatchConfig mFileWatchConfig;
  RegexLogParserConfig mLogParserConfig;
  QString mSourcePath;
  QString mName;
};

#endif  // SETTINGSCONTAINER_H
