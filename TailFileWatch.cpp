#include "TailFileWatch.h"
#include <QDebug>
#include <QFileInfo>
#include <assert.h>

TailFileWatch::TailFileWatch(const QString& filePath, QObject* parent)
  : QObject(parent)
  , mFilePath(filePath)
{
  mTailProcess = new QProcess(this);
  connect(mTailProcess, &QProcess::readyReadStandardOutput, this, &TailFileWatch::fileChanged);
//  QString pathToTail = "C:/cygwin64/bin/tail.exe";
  QString pathToTail = "/usr/bin/tail";
  QStringList arguments;
  arguments << "-n" << "+1" << "-F" << mFilePath;
  mTailProcess->start(pathToTail, arguments);
  qDebug() << "Tail process started";
}

TailFileWatch::~TailFileWatch()
{}

void TailFileWatch::openFile()
{}

void TailFileWatch::setupFileWatcher()
{}

void TailFileWatch::closeHandle()
{}

void TailFileWatch::fileChanged()
{
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

void TailFileWatch::directoryChanged()
{}
