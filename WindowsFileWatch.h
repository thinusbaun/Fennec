#ifndef WINDOWSFILEWATCH_H
#define WINDOWSFILEWATCH_H

#include <QFile>
#include <QFileSystemWatcher>
#include <QObject>
#include <QTextStream>
//#include <windows.h>
//#include <tchar.h>
#include <stdio.h>
//#include <strsafe.h>
//#include <io.h>
class WindowsFileWatch : public QObject
{
    Q_OBJECT

public:
    WindowsFileWatch(const QString &filePath, QObject* parent = nullptr);
    ~WindowsFileWatch();

signals:
    void newLine(const QString& line);

private:
    QString mFilePath;
//    LPCWSTR mWinApiFilePath;
    QFileSystemWatcher mFileSystemWatcher;
    QFile mFile;
    QTextStream mTextStream;
//    HANDLE mHandle;

    void openFile();
    void setupFileWatcher();

    void closeHandle();
private slots:
    void fileChanged();
    void directoryChanged();
};

#endif // WINDOWSFILEWATCH_H
