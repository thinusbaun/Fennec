#include "RegexLogParser.h"

RegexLogParser::RegexLogParser(const QString& regex, QObject* parent)
    : LogParser(parent), mRegExp(QRegularExpression(regex)) {}

void RegexLogParser::parseLine(QString line) {
  QRegularExpressionMatch match = mRegExp.match(line);
  if (match.isValid() && match.hasMatch()) {
    LogEntry entry;
    QStringList captureGroups = mRegExp.namedCaptureGroups();
    for (auto i = 1; i != captureGroups.size(); i++) {
      entry.setPart(captureGroups.at(i), match.captured(i));
    }
    emit lineParsed(entry);
  } else {
    LogEntry entry;
    entry.setPart(mRegExp.namedCaptureGroups().last(), line);
    emit multiLineParsed(entry);
  }
}
