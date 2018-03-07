#ifndef OFFSETLOGPARSER_H
#define OFFSETLOGPARSER_H
#include <core_export.h>
#include "LogParser.h"
class CORE_EXPORT OffsetLogParser : public LogParser {
 public:
  OffsetLogParser();

 public slots:
  virtual void parseLine(QString line);
};

#endif  // OFFSETLOGPARSER_H
