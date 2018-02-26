#include "TailFileWatchFactory.h"
#include "TailFileWatch.h"

#include <QDebug>
#include <QStandardPaths>
TailFileWatchFactory::TailFileWatchFactory(
    const QMap<QString, QVariant>& settings, QObject* parent)
    : QObject(parent), mSettings(settings) {}

TailFileWatch* TailFileWatchFactory::create() {
  qDebug() << "Searching for tail executable";
  QString tailPath = QStandardPaths::findExecutable("tail");
  if (tailPath.isEmpty()) {
    qWarning() << "tail executable not found in PATH";
  } else {
    qDebug() << "Found tail executable path: " << tailPath;
  }
  return new TailFileWatch(tailPath,
                           mSettings["TAIL_ADDITIONAL_ARGS"].toStringList(),
                           mSettings["TAIL_FILE_PATH"].toString());
}
