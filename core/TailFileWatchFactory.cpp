#include "TailFileWatchFactory.h"
#include "TailFileWatch.h"

TailFileWatchFactory::TailFileWatchFactory(
    const QMap<QString, QVariant> &settings, QObject *parent)
    : QObject(parent), mSettings(settings) {}

TailFileWatch *TailFileWatchFactory::create() {
  return new TailFileWatch(mSettings["TAIL_FILE_PATH"].toString());
}
