#include "RegexLogParser.h"

RegexLogParser::RegexLogParser(const QString &regex, QObject *parent)
    : LogParser(parent), mRegExp(QRegularExpression(regex)) {}

void RegexLogParser::parseLine(QString line) {
  QRegularExpressionMatch match = mRegExp.match(line);
  if (match.isValid() && match.hasMatch()) {
    LogEntry entry;
    for (auto i = 1; i != mRegExp.namedCaptureGroups().size(); i++) {
      entry.setPart(mRegExp.namedCaptureGroups().at(i), match.captured(i));
    }
    emit lineParsed(entry);
  } else {
    LogEntry entry;
    entry.setPart(mRegExp.namedCaptureGroups().last(), line);
    emit multiLineParsed(entry);
  }
}
