#include "RegexLogParserFactory.h"
#include "RegexLogParser.h"

RegexLogParserFactory::RegexLogParserFactory(
    const QMap<QString, QVariant> &settings, QObject *parent)
    : QObject(parent), mSettings(settings) {}

RegexLogParser *RegexLogParserFactory::create() {
  return new RegexLogParser(mSettings["PARSER_REGEX"].toString());
}
