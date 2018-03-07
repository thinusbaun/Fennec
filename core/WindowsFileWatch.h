#ifndef WINDOWSFILEWATCH_H
#define WINDOWSFILEWATCH_H

#ifdef WIN32

#include <core_export.h>
#include <io.h>
#include <stdio.h>
#include <strsafe.h>
#include <tchar.h>
#include <windows.h>
#include <QFile>
#include <QFileSystemWatcher>
#include <QObject>
#include <QTextStream>

class CORE_EXPORT WindowsFileWatch : public QObject {
  Q_OBJECT

 public:
  WindowsFileWatch(const QString &filePath, QObject *parent = nullptr);
  ~WindowsFileWatch();

 signals:
  void newLine(const QString &line);

 private:
  QString mFilePath;
  LPCWSTR mWinApiFilePath;
  QFileSystemWatcher mFileSystemWatcher;
  QFile mFile;
  QTextStream mTextStream;
  HANDLE mHandle;

  void openFile();
  void setupFileWatcher();

  void closeHandle();
 private slots:
  void fileChanged();
  void directoryChanged();
};

#endif
#endif  // WINDOWSFILEWATCH_H
