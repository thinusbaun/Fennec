#include <QAction>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMenuBar>
#include <QMessageBox>
#include <QStandardPaths>
#include <QTabWidget>
#include <QTableView>
#include <QWidget>

#include <QDebug>
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
  loadSettings();
  QWidget* mainWidget = new QWidget(this);
  QHBoxLayout* layout = new QHBoxLayout();
  mainWidget->setLayout(layout);
  setCentralWidget(mainWidget);

  QTabWidget* tabWidget = new QTabWidget();
  layout->addWidget(tabWidget);

  LogViewTabManager manager(tabWidget, mSettings, mSettingsProvider);
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
  connect(settingsAction, &QAction::triggered, mSettingsDialog, &QDialog::exec);
  connect(mSettingsDialog, &QDialog::accepted, this, &MainWindow::saveSettings);
}

void MainWindow::loadSettings() {
  qDebug() << "Trying to load settings from file";
  QString configPath =
      QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation);
  if (!configPath.isEmpty()) {
    QFile configFile(configPath + "/FennecConfig.json");
    qDebug() << "Trying location: " << configFile.fileName();
    if (configFile.exists()) {
      configFile.open(QIODevice::ReadOnly);
      QString errorString;
      if (!mSettingsProvider.trySaveSettings(configFile.readAll(), errorString,
                                             true)) {
        auto messageBox = new QMessageBox();
        messageBox->addButton(QMessageBox::Ok);
        messageBox->setText(errorString);
        messageBox->show();
        qDebug() << "Loading settings failed: " << errorString;
      }
      qDebug() << "Settings loaded";
      configFile.close();
    } else {
      qDebug() << "Config file does not exist";
    }
  }
}

void MainWindow::saveSettings() {
  qDebug() << "Trying to save settings to file";
  QString configPath =
      QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation);
  if (!configPath.isEmpty()) {
    QFile configFile(configPath + "/FennecConfig.json");
    qDebug() << "Trying location: " << configFile.fileName();
    configFile.open(QIODevice::WriteOnly);
    QByteArray settings = mSettingsProvider.getJsonSettings().toJson();
    qDebug() << "Writing settings: " << settings;
    configFile.write(settings);
    configFile.close();
  }
}
