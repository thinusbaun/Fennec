#include "TailFileWatch.h"
#include <QDebug>
#include <QFileInfo>
#include <assert.h>

TailFileWatch::TailFileWatch(const QString &tailPath,
                             const QStringList &tailArgs,
                             const QString &filePath, QObject *parent)
    : QObject(parent), mTailPath(tailPath), mTailArgs(tailArgs),
      mFilePath(filePath) {
  mTailProcess = new QProcess(this);
  connect(mTailProcess, &QProcess::readyReadStandardOutput, this,
          &TailFileWatch::fileChanged);
}

TailFileWatch::~TailFileWatch() { closeHandle(); }

void TailFileWatch::openFile() {
  QStringList arguments = mTailArgs;
  arguments << "-F" << mFilePath;
  mTailProcess->start(mTailPath, arguments);
  qDebug() << "Tail process started";
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
