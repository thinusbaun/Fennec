#include <QApplication>
#include <QDir>
#include <QSettings>
#include "MainWindow.h"
#include "SettingsProvider.h"

int main(int argc, char* argv[])
{
    QSettings* settings = new QSettings(QDir::currentPath()+"/logger_conf.ini", QSettings::IniFormat);
//    settings->beginGroup("LOGGERS");
//    settings->beginGroup("ASD");
//    settings->setValue("qwe", "ASD");
//    settings->endGroup();
//    settings->endGroup();
    settings->sync();
  QApplication a(argc, argv);
  SettingsProvider provider(settings);
  provider.getAllLoggersSettings();
  MainWindow window;
  window.show();
  window.centerAndResize();
  return a.exec();
}
