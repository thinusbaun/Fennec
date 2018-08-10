#include "LogRowColorizer.h"
#include "LogEntry.h"
#include "SettingsProvider.h"

LogRowColorizer::LogRowColorizer(const LogRowColorizerConfig& config)
    : mConfig(config) {}

QBrush LogRowColorizer::getBrushForEntry(const LogEntry& entry) const {
  QString partValue = entry.getPart(mConfig.partName()).toString();
  return QBrush(QColor(mConfig.getColorForValue(partValue)));
}
