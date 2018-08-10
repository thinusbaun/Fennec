#include "RegexLogParserFactory.h"
#include "RegexLogParser.h"

RegexLogParserFactory::RegexLogParserFactory(SettingsProvider& settingsProvider,
                                             QObject* parent)
    : QObject(parent), mSettingsProvider(settingsProvider) {}

RegexLogParser* RegexLogParserFactory::create() {
  return new RegexLogParser(mSettingsProvider.getContainer().logParserConfig());
}
