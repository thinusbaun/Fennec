#include "LogModelFactory.h"
#include "LogModel.h"

LogModelFactory::LogModelFactory(const QMap<QString, QVariant> &settings,
                                 QObject *parent)
    : QObject(parent), mSettings(settings) {}

LogModelFactory::~LogModelFactory() {}

LogModel *LogModelFactory::create() {
  return new LogModel(mSettings["HEADERS"].toStringList());
}
