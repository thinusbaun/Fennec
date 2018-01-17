#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);

  void centerAndResize();

private:
  static QMap<QString, QVariant> mSettings;
};

#endif // MAINWINDOW_H
