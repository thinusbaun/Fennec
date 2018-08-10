#ifndef LOGROWCOLORIZER_H
#define LOGROWCOLORIZER_H

#include "LogRowColorizerConfig.h"

#include <QBrush>
#include <QMap>
class LogEntry;
class SettingsProvider;

class LogRowColorizer {
 public:
  LogRowColorizer(const LogRowColorizerConfig& config);

  QBrush getBrushForEntry(const LogEntry& entry) const;

 private:
  LogRowColorizerConfig mConfig;
};

#endif  // LOGROWCOLORIZER_H
