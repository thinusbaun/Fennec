#include "RegexLogParserFactory.h"
#include "RegexLogParser.h"

RegexLogParserFactory::RegexLogParserFactory(const SingleLogSetting& settings,
                                             QObject* parent)
    : QObject(parent), mSettings(settings) {}

RegexLogParser* RegexLogParserFactory::create() {
  return new RegexLogParser(mSettings.logParserConfig());
}
