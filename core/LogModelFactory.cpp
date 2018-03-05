#include "LogModelFactory.h"
#include "LogModel.h"
#include "LogRowColorizer.h"
#include "SettingsProvider.h"

LogModelFactory::LogModelFactory(SettingsProvider& settingsProvider,
                                 QObject* parent)
    : QObject(parent), mSettingsProvider(settingsProvider) {}

LogModelFactory::~LogModelFactory() {}

LogModel* LogModelFactory::create() {
  auto config = mSettingsProvider.getSettingsFor("LogModel").toMap();
  return new LogModel(
      config["Headers"].toStringList(),
      config.contains("LimitRows") ? config["LimitRows"].toInt() : -1,
      new LogRowColorizer(mSettingsProvider));
}
