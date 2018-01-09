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
#include <QProcess>

class TailFileWatch : public QObject {
  Q_OBJECT

public:
  TailFileWatch(const QString &filePath, QObject *parent = nullptr);
  ~TailFileWatch();

signals:
  void newLine(const QString &line);

private:
  QString mFilePath;
  QProcess *mTailProcess;

  void openFile();
  void setupFileWatcher();

  void closeHandle();
private slots:
  void fileChanged();
  void directoryChanged();
};

#endif // TAILFILEWATCH_H
