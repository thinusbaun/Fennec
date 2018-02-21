#include "OffsetLogParser.h"
#include <QDateTime>
#include <QDebug>
#include "LogEntry.h"

QDebug operator<<(QDebug debug, const LogEntry& c) {
  //  debug << c.timestamp().toString(Qt::ISODate);
  //  debug << c.level();
  //  debug << c.subsystem();
  //  debug << c.content();
  debug << c.getPartsMap();
  return debug;
}
OffsetLogParser::OffsetLogParser() {}

void OffsetLogParser::parseLine(QString line) {
  //    qDebug() <<line;
  LogEntry entry;
  QDateTime timestamp =
      QDateTime::fromString(line.mid(0, 19), "HH:mm:ss dd/MM/yyyy");
  if (timestamp.isValid()) {
    entry.setPart("TIMESTAMP", timestamp);
    entry.setPart("LEVEL", line.mid(20, 3));
    entry.setPart("SUBSYSTEM", line.mid(26, 8));
    entry.setPart("CONTENT", line.mid(36));
    //  qDebug() << entry;
    emit lineParsed(entry);
  } else {
    entry.setPart("CONTENT", line);
    emit multiLineParsed(entry);
  }
}
