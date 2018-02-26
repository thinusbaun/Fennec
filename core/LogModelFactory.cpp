#include "LogModelFactory.h"
#include "LogModel.h"
#include "LogRowColorizer.h"
#include "SettingsProvider.h"

LogModelFactory::LogModelFactory(const QMap<QString, QVariant>& settings,
                                 SettingsProvider& settingsProvider,
                                 QObject* parent)
    : QObject(parent),
      mSettings(settings),
      mSettingsProvider(settingsProvider) {}

LogModelFactory::~LogModelFactory() {}

LogModel* LogModelFactory::create() {
  return new LogModel(mSettings["HEADERS"].toStringList(),
                      new LogRowColorizer(mSettingsProvider));
}
