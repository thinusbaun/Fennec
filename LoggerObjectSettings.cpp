#include "LoggerObjectSettings.h"

LoggerObjectSettings::LoggerObjectSettings()
{

}

QStringList LoggerObjectSettings::headers() const
{
    return mHeaders;
}

void LoggerObjectSettings::setHeaders(const QStringList &headers)
{
    mHeaders = headers;
}

QString LoggerObjectSettings::logWatchName() const
{
    return mLogWatchName;
}

void LoggerObjectSettings::setLogWatchName(const QString &logWatchName)
{
    mLogWatchName = logWatchName;
}

QString LoggerObjectSettings::logParserName() const
{
    return mLogParserName;
}

void LoggerObjectSettings::setLogParserName(const QString &logParserName)
{
    mLogParserName = logParserName;
}

QString LoggerObjectSettings::filePath() const
{
    return mFilePath;
}

void LoggerObjectSettings::setFilePath(const QString &filePath)
{
    mFilePath = filePath;
}

QString LoggerObjectSettings::name() const
{
    return mName;
}

void LoggerObjectSettings::setName(const QString &name)
{
    mName = name;
}
