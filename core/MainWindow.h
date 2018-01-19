#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>

class QTableView;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);

  void centerAndResize();

  QTableView *asd();

private:
  static QMap<QString, QVariant> mSettings;
  QTableView *mTableView;
};

#endif // MAINWINDOW_H
