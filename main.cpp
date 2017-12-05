#include <QApplication>
#include "TailFileWatch.h"
#include "OffsetLogParser.h"
#include "MainWindow.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileSystemWatcher>
#include <QObject>
#include <QElapsedTimer>

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
//  TailFileWatch watch("C:/Users/katnerm/AppData/Local/Transition Technologies S.A/MidOSS/client.log");
//  OffsetLogParser parser;
//  a.connect(&watch, &TailFileWatch::newLine, &parser, &LogParser::parseLine);
//  QElapsedTimer timer;
//  timer.start();
//  for (long i = 0; i < 10000; i++) {
//    parser.parseLine("12:38:28 24/10/2017 Deb: [XML_:___] XmlDataLogger::log name='clientModuleInfo'");
//  }
//  qDebug() << timer.elapsed()/1000.0;
  MainWindow window;
  window.show();
  window.centerAndResize();

  return a.exec();
}
