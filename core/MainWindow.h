#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SettingsDialog.h"
#include "SettingsProvider.h"

#include <core_export.h>
#include <QtWidgets/QMainWindow>

class QTableView;

class CORE_EXPORT MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = nullptr);

  void centerAndResize();

  void setBasicWindowName(const QString &name);

private slots:
  void saveSettings();

 private:
  static QMap<QString, QVariant> mSettings;
  QTableView *mTableView;
  QString mBasicName;

  SettingsDialog *mSettingsDialog;
  SettingsProvider mSettingsProvider;

  void createMenu();

  void loadSettings();


};

#endif  // MAINWINDOW_H
