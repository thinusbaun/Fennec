#ifndef TAILFILEWATCHFACTORY_H
#define TAILFILEWATCHFACTORY_H

#include <QMap>
#include <QObject>
#include <QString>
#include <QVariant>
#include <core_export.h>

class TailFileWatch;

class CORE_EXPORT TailFileWatchFactory : public QObject {
  Q_OBJECT
public:
  TailFileWatchFactory(const QMap<QString, QVariant> &settings,
                       QObject *parent = nullptr);

  TailFileWatch *create();

private:
  const QMap<QString, QVariant> mSettings;
};

#endif // TAILFILEWATCHFACTORY_H
