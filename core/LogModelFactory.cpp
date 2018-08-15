#include "LogModelFactory.h"
#include "LogModel.h"
#include "LogRowColorizer.h"
#include "SingleLogSetting.h"

LogModelFactory::LogModelFactory(const SingleLogSetting& settings,
                                 QObject* parent)
    : QObject(parent), mSettings(settings) {}

LogModelFactory::~LogModelFactory() {}

LogModel* LogModelFactory::create() {
  return new LogModel(mSettings.logModelConfig(),
                      new LogRowColorizer(mSettings.logRowColorizerConfig()));
}
