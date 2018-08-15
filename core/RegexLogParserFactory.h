#ifndef REGEXLOGPARSERFACTORY_H
#define REGEXLOGPARSERFACTORY_H

#include <core_export.h>
#include <QMap>
#include <QObject>
#include <QString>
#include <QVariant>
#include "SingleLogSetting.h"

class RegexLogParser;

class CORE_EXPORT RegexLogParserFactory : public QObject {
  Q_OBJECT
 public:
  explicit RegexLogParserFactory(const SingleLogSetting &settings,
                                 QObject *parent = nullptr);

  RegexLogParser *create();

 private:
  const SingleLogSetting &mSettings;
};

#endif  // REGEXLOGPARSERFACTORY_H
