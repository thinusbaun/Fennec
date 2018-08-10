#include "TailFileWatch.h"
#include <assert.h>
#include <QDebug>
#include <QFileInfo>

TailFileWatch::TailFileWatch(const TailFileWatchConfig& config,
                             const QString& filePath, QObject* parent)
    : QObject(parent), mConfig(config), mFilePath(filePath) {
  mTailProcess = new QProcess(this);
  connect(mTailProcess, &QProcess::readyReadStandardOutput, this,
          &TailFileWatch::fileChanged);
  connect(mTailProcess, &QProcess::readyReadStandardError, this,
          &TailFileWatch::stdErrOutput);
}

TailFileWatch::~TailFileWatch() { closeHandle(); }

void TailFileWatch::openFile() {
  QStringList arguments = mConfig.args();
  arguments << "-F" << mFilePath;
  qDebug() << "Tail path: " << mConfig.processPath();
  qDebug() << "Tail process args: " << arguments;
  mTailProcess->start(mConfig.processPath(), arguments);
  mTailProcess->waitForStarted();
  qDebug() << "Tail process id: " << mTailProcess->processId();
  if (mTailProcess->state() == QProcess::Running) {
    qDebug() << "Tail process started";
  } else {
    qDebug() << "Tail process not started. Error: "
             << mTailProcess->errorString();
  }
}

void TailFileWatch::setupFileWatcher() {}

void TailFileWatch::closeHandle() {
  mTailProcess->close();
  qDebug() << "Tail process stopped";
}

void TailFileWatch::fileChanged() {
  char buff[1024];
  qDebug() << "File change detected";
  while (mTailProcess->canReadLine()) {
    qint64 read = mTailProcess->readLine(buff, 1024);
    if (read != -1) {
      QString temp = QString::fromLatin1(buff, read).trimmed();
      //      qDebug() << temp;
      emit newLine(temp);
    }
  }
}

void TailFileWatch::directoryChanged() {}

void TailFileWatch::stdErrOutput() {
  qDebug() << mTailProcess->readAllStandardError();
}
