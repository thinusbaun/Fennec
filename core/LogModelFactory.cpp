#include "LogModelFactory.h"
#include "LogModel.h"
#include "LogRowColorizer.h"
#include "SettingsContainer.h"
#include "SettingsProvider.h"

LogModelFactory::LogModelFactory(SettingsProvider& settingsProvider,
                                 QObject* parent)
    : QObject(parent), mSettingsProvider(settingsProvider) {}

LogModelFactory::~LogModelFactory() {}

LogModel* LogModelFactory::create() {
  auto config = mSettingsProvider.getSettingsFor("LogModel").toMap();
  return new LogModel(
      mSettingsProvider.getContainer().logModelConfig(),
      new LogRowColorizer(
          mSettingsProvider.getContainer().logRowColorizerConfig()));
}
