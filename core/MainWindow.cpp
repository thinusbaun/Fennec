#include <QAction>
#include <QApplication>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMenuBar>
#include <QTabWidget>
#include <QTableView>
#include <QWidget>

#include "LogViewTabManager.h"
#include "version.h"

#include "MainWindow.h"

QMap<QString, QVariant> MainWindow::mSettings{
    {"HEADERS", QStringList({"TIMESTAMP", "LEVEL", "SUBSYSTEM", "CONTENT"})},
    {"TAIL_PATH", "/usr/bin/tail"},
    {"TAIL_ADDITIONAL_ARGS", QStringList({"-n", "+1"})},
    {"TAIL_FILE_PATH", "/mnt/winda/untitled12/core/example.log"},
    {"PARSER_REGEX",
     R"(^(?<TIMESTAMP>\d{2}:\d{2}:\d{2} \d{2}\/\d{2}\/\d{4}) (?<LEVEL>\w*): \[(?<SUBSYSTEM>.*:.*)\] (?<CONTENT>.*)$)"}};

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  QWidget* mainWidget = new QWidget(this);
  QHBoxLayout* layout = new QHBoxLayout();
  mainWidget->setLayout(layout);
  setCentralWidget(mainWidget);

  QTabWidget* tabWidget = new QTabWidget();
  layout->addWidget(tabWidget);

  LogViewTabManager manager(tabWidget, mSettings);
  manager.createViews();

  mSettingsDialog =
      new SettingsDialog(this, Qt::WindowFlags(), mSettingsProvider);
  createMenu();
}

void MainWindow::centerAndResize() {
  // get the dimension available on this screen
  QDesktopWidget* desktopWidget = QApplication::desktop();
  QSize availableSize = desktopWidget->availableGeometry().size();
  int width = availableSize.width();
  int height = availableSize.height();
  //  qDebug() << "Available dimensions " << width << "x" << height;
  width *= 0.9;   // 90% of the screen size
  height *= 0.9;  // 90% of the screen size
  //  qDebug() << "Computed dimensions " << width << "x" << height;
  QSize newSize(width, height);

  setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, newSize,
                                  desktopWidget->availableGeometry()));
}

void MainWindow::setBasicWindowName(const QString& name) {
  mBasicName = QString("%1(%2 %3)")
                   .arg(name, Fennec::gitBranch, Fennec::gitCommitNumber);
  setWindowTitle(mBasicName);
}

void MainWindow::createMenu() {
  auto settingsAction = menuBar()->addAction("Settings");
  connect(settingsAction, &QAction::triggered, mSettingsDialog, &QDialog::show);
}
