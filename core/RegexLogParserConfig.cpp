#include "RegexLogParserConfig.h"

RegexLogParserConfig::RegexLogParserConfig() {}

void RegexLogParserConfig::read(const QJsonObject &json) {
  mRegex = json["regex"].toString();
}

void RegexLogParserConfig::write(QJsonObject &json) const {
  json["regex"] = mRegex;
}

QString RegexLogParserConfig::regex() const { return mRegex; }

void RegexLogParserConfig::setRegex(const QString &regex) { mRegex = regex; }
