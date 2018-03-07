#include "RegexLogParserFactory.h"
#include "RegexLogParser.h"

RegexLogParserFactory::RegexLogParserFactory(SettingsProvider& settingsProvider,
                                             QObject* parent)
    : QObject(parent), mSettingsProvider(settingsProvider) {}

RegexLogParser* RegexLogParserFactory::create() {
  auto config = mSettingsProvider.getSettingsFor("RegexLogParser").toMap();
  return new RegexLogParser(config["ParserRegex"].toString());
}
