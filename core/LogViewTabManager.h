#ifndef LOGVIEWTABMANAGER_H
#define LOGVIEWTABMANAGER_H

#include <QMap>
#include <QObject>
#include <QString>
#include <QTabWidget>
#include <QVariant>

class LogViewTabManager : public QObject {
  Q_OBJECT
public:
  explicit LogViewTabManager(QTabWidget *widgetToManage,
                             const QMap<QString, QVariant> &settings,
                             QObject *parent = nullptr);

  void createViews();

private:
  QTabWidget *mWidget;
  const QMap<QString, QVariant> mSettings;
};

#endif // LOGVIEWTABMANAGER_H
