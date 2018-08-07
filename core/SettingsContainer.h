#ifndef SETTINGSCONTAINER_H
#define SETTINGSCONTAINER_H

#include <QJsonObject>

class SettingsContainer {
 public:
  SettingsContainer();

  void read(const QJsonObject& json);
  void write(QJsonObject& json) const;
};

#endif  // SETTINGSCONTAINER_H
