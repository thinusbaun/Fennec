#ifndef REGEXLOGPARSERFACTORY_H
#define REGEXLOGPARSERFACTORY_H

#include <QMap>
#include <QObject>
#include <QString>
#include <QVariant>

class RegexLogParser;

class RegexLogParserFactory : public QObject {
  Q_OBJECT
public:
  explicit RegexLogParserFactory(const QMap<QString, QVariant> &settings,
                                 QObject *parent = nullptr);

  RegexLogParser *create();

private:
  const QMap<QString, QVariant> mSettings;
};

#endif // REGEXLOGPARSERFACTORY_H
