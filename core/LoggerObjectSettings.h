#ifndef LOGGEROBJECTSETTINGS_H
#define LOGGEROBJECTSETTINGS_H

#include <QString>
#include <QStringList>

class LoggerObjectSettings {
public:
  LoggerObjectSettings();

  QStringList headers() const;
  void setHeaders(const QStringList &headers);

  QString logWatchName() const;
  void setLogWatchName(const QString &logWatchName);

  QString logParserName() const;
  void setLogParserName(const QString &logParserName);

  QString filePath() const;
  void setFilePath(const QString &filePath);

  QString name() const;
  void setName(const QString &name);

private:
  QString mName;
  QStringList mHeaders;
  QString mLogWatchName;
  QString mLogParserName;
  QString mFilePath;
};

#endif // LOGGEROBJECTSETTINGS_H
