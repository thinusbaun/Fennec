#ifndef TAILFILEWATCH_H
#define TAILFILEWATCH_H

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
  TailFileWatch(const QString &tailPath, const QStringList &tailArgs,
                const QString &filePath, QObject *parent = nullptr);
  ~TailFileWatch();
  void openFile();

 signals:
  void newLine(const QString &line);

 private:
  QString mTailPath;
  QStringList mTailArgs;
  QString mFilePath;
  QProcess *mTailProcess;

  void setupFileWatcher();

  void closeHandle();
 private slots:
  void fileChanged();
  void directoryChanged();
};

#endif  // TAILFILEWATCH_H
