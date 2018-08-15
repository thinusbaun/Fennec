#include "TailFileWatchFactory.h"
#include <QDebug>
#include <QStandardPaths>

#include "TailFileWatch.h"
TailFileWatchFactory::TailFileWatchFactory(const SingleLogSetting& settings,
                                           QObject* parent)
    : QObject(parent), mSettings(settings) {}

TailFileWatch* TailFileWatchFactory::create() {
  //  auto config = mSettingsProvider.getSettingsFor("TailFileWatch").toMap();
  //  QString tailPath;
  //  if (config.contains("TailExecutablePath")) {
  //    qDebug() << "Tail executable path provided from config";
  //    tailPath = config["TailExecutablePath"].toString();
  //  } else {
  //    qDebug() << "Searching for tail executable";
  //    tailPath = QStandardPaths::findExecutable("tail");
  //  }
  //  if (tailPath.isEmpty()) {
  //    qWarning() << "Tail executable not found in PATH or in config";
  //  } else {
  //    qDebug() << "Tail executable path: " << tailPath;
  //  }
  return new TailFileWatch(mSettings.fileWatchConfig(), mSettings.sourcePath());
}
