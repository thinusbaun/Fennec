#ifndef LOGVIEWTABMANAGER_H
#define LOGVIEWTABMANAGER_H

#include <core_export.h>
#include <QMap>
#include <QObject>
#include <QString>
#include <QTabWidget>
#include <QVariant>

class SettingsProvider;
class CORE_EXPORT LogViewTabManager : public QObject {
  Q_OBJECT
 public:
  explicit LogViewTabManager(QTabWidget *widgetToManage,
                             const QMap<QString, QVariant> &settings,
                             SettingsProvider &settingsProvider,
                             QObject *parent = nullptr);

  void createViews();

 private:
  QTabWidget *mWidget;
  const QMap<QString, QVariant> mSettings;
  SettingsProvider &mSettingsProvider;
};

#endif  // LOGVIEWTABMANAGER_H
