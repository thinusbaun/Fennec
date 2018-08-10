#ifndef REGEXLOGPARSERFACTORY_H
#define REGEXLOGPARSERFACTORY_H

#include <core_export.h>
#include <QMap>
#include <QObject>
#include <QString>
#include <QVariant>
#include "SettingsProvider.h"

class RegexLogParser;

class CORE_EXPORT RegexLogParserFactory : public QObject {
  Q_OBJECT
 public:
  explicit RegexLogParserFactory(SettingsProvider &settingsProvider,
                                 QObject *parent = nullptr);

  RegexLogParser *create();

 private:
  SettingsProvider &mSettingsProvider;
};

#endif  // REGEXLOGPARSERFACTORY_H
