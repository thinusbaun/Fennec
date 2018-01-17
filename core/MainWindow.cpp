#include "TailFileWatchFactory.h"
#include <ContentItemDelegate.h>
#include <LogEntry.h>
#include <LogModel.h>
#include <OffsetLogParser.h>
#include <QApplication>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QTableView>
#include <QWidget>
#include <TailFileWatch.h>

#include "LogModelFactory.h"
#include "MainWindow.h"
#include "RegexLogParser.h"
#include "RegexLogParserFactory.h"

QMap<QString, QVariant> MainWindow::mSettings{
    {"HEADERS", QStringList({"TIMESTAMP", "LEVEL", "SUBSYSTEM", "CONTENT"})},
    {"TAIL_PATH", "/usr/bin/tail"},
    {"TAIL_ADDITIONAL_ARGS", QStringList({"-n", "+1"})},
    {"TAIL_FILE_PATH", "/mnt/winda/untitled12/core/example.log"},
    {"PARSER_REGEX",
     R"(^(?<TIMESTAMP>\d{2}:\d{2}:\d{2} \d{2}\/\d{2}\/\d{4}) (?<LEVEL>\w*): \[(?<SUBSYSTEM>.*:.*)\] (?<CONTENT>.*)$)"}};

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  QWidget *mainWidget = new QWidget(this);
  QHBoxLayout *layout = new QHBoxLayout();
  mainWidget->setLayout(layout);
  setCentralWidget(mainWidget);

  QTableView *tableView = new QTableView(this);
  tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

  LogModelFactory factory(mSettings, this);
  LogModel *model = factory.create();
  tableView->setModel(model);
  tableView->horizontalHeader()->setStretchLastSection(true);
  tableView->setItemDelegateForColumn(3, new ContentItemDelegate());
  layout->addWidget(tableView);

  TailFileWatchFactory watchFactory(mSettings, this);
  TailFileWatch *watch = watchFactory.create();

  RegexLogParserFactory parserFactory(mSettings, this);
  RegexLogParser *parser = parserFactory.create();

  connect(watch, &TailFileWatch::newLine, parser, &LogParser::parseLine);
  connect(parser, &LogParser::multiLineParsed, model, &LogModel::mergeLastRow);
  connect(parser, &LogParser::lineParsed, model, &LogModel::addRow);
}

void MainWindow::centerAndResize() {
  // get the dimension available on this screen
  QDesktopWidget *desktopWidget = QApplication::desktop();
  QSize availableSize = desktopWidget->availableGeometry().size();
  int width = availableSize.width();
  int height = availableSize.height();
  qDebug() << "Available dimensions " << width << "x" << height;
  width *= 0.9;  // 90% of the screen size
  height *= 0.9; // 90% of the screen size
  qDebug() << "Computed dimensions " << width << "x" << height;
  QSize newSize(width, height);

  setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, newSize,
                                  desktopWidget->availableGeometry()));
}
