#ifndef TAILFILEWATCHFACTORY_H
#define TAILFILEWATCHFACTORY_H

#include <QMap>
#include <QObject>
#include <QString>
#include <QVariant>

class TailFileWatch;

class TailFileWatchFactory : public QObject {
  Q_OBJECT
public:
  TailFileWatchFactory(const QMap<QString, QVariant> &settings,
                       QObject *parent = nullptr);

  TailFileWatch *create();

private:
  const QMap<QString, QVariant> mSettings;
};

#endif // TAILFILEWATCHFACTORY_H
