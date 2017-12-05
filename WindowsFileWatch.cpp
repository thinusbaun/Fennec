#include "WindowsFileWatch.h"
#include <QDebug>
#include <QFileInfo>
//#include <Shlwapi.h>
#include <assert.h>

WindowsFileWatch::WindowsFileWatch(const QString& filePath, QObject* parent)
  : QObject(parent)
  , mFilePath(filePath)
{
  bool connectOk = connect(&mFileSystemWatcher, &QFileSystemWatcher::fileChanged, this, &WindowsFileWatch::fileChanged);
  assert(connectOk);
  connectOk = connect(&mFileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &WindowsFileWatch::directoryChanged);
  assert(connectOk);

  openFile();
  setupFileWatcher();
}

WindowsFileWatch::~WindowsFileWatch()
{}

void WindowsFileWatch::openFile()
{
//  mWinApiFilePath = reinterpret_cast<const wchar_t*>(mFilePath.utf16());
//  mHandle = CreateFile(mWinApiFilePath,
//                       GENERIC_READ,
//                       FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE,
//                       NULL,
//                       OPEN_EXISTING,
//                       NULL,
//                       NULL
//                       );

//  int file_handle = _open_osfhandle(reinterpret_cast<intptr_t>(mHandle), 0);

//  mFile.open(file_handle, QIODevice::ReadOnly);
//  mTextStream.setDevice(&mFile);
//  mTextStream.reset();

//  qDebug() << "OpenFile end";
//  qDebug() << "Opened file desctiptor: " << file_handle;
//  fileChanged();
}

void WindowsFileWatch::setupFileWatcher()
{
  mFileSystemWatcher.addPath(mFilePath);
  mFileSystemWatcher.addPath(QFileInfo(mFilePath).path());

  qDebug() << "fileWatcher setup done";
}

void WindowsFileWatch::closeHandle()
{
  CloseHandle(mHandle);
  mHandle = nullptr;
  mFile.close();
  qDebug() << "Handle closed";
}

void WindowsFileWatch::fileChanged()
{
  qDebug() << "File change detected";
//  if (!PathFileExistsW(mWinApiFilePath)) {
//    qDebug() << "File closed";
//    closeHandle();
//    return;
//  }
//  QString line = mTextStream.readLine(0);
//  if (!line.isEmpty()) {
//    qDebug() << line;
//  }
//  while (true) {
//    line = mTextStream.readLine(0);

//    if (!line.isEmpty()) {
//      qDebug() << line;
//      emit newLine(line);
//    } else {
//      break;
//    }
//  }
}

void WindowsFileWatch::directoryChanged()
{
  qDebug() << "Directory content change detected";
//  if (mHandle == nullptr) {
//    if (PathFileExistsW(mWinApiFilePath)) {
//      openFile();
//    }
//  }
}
