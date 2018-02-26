#include "LogRowColorizer.h"
#include "LogEntry.h"
#include "SettingsProvider.h"

LogRowColorizer::LogRowColorizer(SettingsProvider& settingsProvider)
    : mSettingsProvider(settingsProvider) {
  getConfiguration();
}

QBrush LogRowColorizer::getBrushForEntry(const LogEntry& entry) const {
  QString partValue = entry.getPart(mPartName).toString();
  return QBrush(QColor(mColorsMap.value(partValue, "transparent")));
}

void LogRowColorizer::getConfiguration() {
  QMap<QString, QVariant> settings =
      mSettingsProvider.getSettingsFor("LogRowColorizer").toMap();
  mPartName = settings["EntryPart"].toString();
  auto colorsMap = settings["Colors"].toMap();
  for (auto it = colorsMap.cbegin(); it != colorsMap.cend(); it++) {
    mColorsMap[it.key()] = it.value().toString();
  }
}
