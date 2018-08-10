#ifndef TAILFILEWATCH_H
#define TAILFILEWATCH_H

#include "TailFileWatchConfig.h"

#include <QFile>
#include <QFileSystemWatcher>
#include <QObject>
#include <QTextStream>
//#include <windows.h>
//#include <tchar.h>
#include <stdio.h>
//#include <strsafe.h>
//#include <io.h>
#include <core_export.h>
#include <QProcess>

class CORE_EXPORT TailFileWatch : public QObject {
  Q_OBJECT

 public:
  TailFileWatch(const TailFileWatchConfig &config, const QString &filePath,
                QObject *parent = nullptr);
  ~TailFileWatch();
  void openFile();

 signals:
  void newLine(const QString &line);

 private:
  TailFileWatchConfig mConfig;
  QString mFilePath;
  QProcess *mTailProcess;

  void setupFileWatcher();

  void closeHandle();
 private slots:
  void fileChanged();
  void directoryChanged();
  void stdErrOutput();
};

#endif  // TAILFILEWATCH_H
