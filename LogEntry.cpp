#include "LogEntry.h"

LogEntry::LogEntry()
{}

void LogEntry::setPart(const QString &name, const QVariant &value)
{
    mPartsMap[name] = value;
}

QVariant LogEntry::getPart(const QString &name) const
{
    return mPartsMap[name];
}

const QMap<QString, QVariant> LogEntry::getPartsMap() const
{
    return mPartsMap;
}

bool LogEntry::isPartMultiline(const QString &part) const
{
    if (mMultilinesMap.contains(part))
    {
        return mMultilinesMap[part];
    }
    return false;
}

void LogEntry::merge(const LogEntry &entry)
{
    for(auto it = entry.getPartsMap().begin(); it != entry.getPartsMap().end(); it++)
    {
        if (!mPartsMap.contains(it.key()) || !mPartsMap[it.key()].canConvert(QVariant::String))
        {
            mPartsMap[it.key()] = it.value();
        } else if (mPartsMap[it.key()].canConvert(QVariant::String))
        {
            mPartsMap[it.key()] = mPartsMap[it.key()].toString() + QString("\n") + it.value().toString();
            mMultilinesMap[it.key()] = true;
        }
    }

}

