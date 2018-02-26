#ifndef LOGROWCOLORIZER_H
#define LOGROWCOLORIZER_H

#include <QBrush>
#include <QMap>
class LogEntry;
class SettingsProvider;

class LogRowColorizer {
 public:
  LogRowColorizer(SettingsProvider& settingsProvider);

  QBrush getBrushForEntry(const LogEntry& entry) const;

 private:
  SettingsProvider& mSettingsProvider;
  QString mPartName;
  QMap<QString, QString> mColorsMap;

  void getConfiguration();
};

#endif  // LOGROWCOLORIZER_H
