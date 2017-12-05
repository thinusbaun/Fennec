#include <QWidget>
#include <QHBoxLayout>
#include <QTableView>
#include <LogEntry.h>
#include <LogModel.h>
#include <OffsetLogParser.h>
#include <TailFileWatch.h>
#include <ContentItemDelegate.h>
#include <QHeaderView>
#include <QApplication>
#include <QDesktopWidget>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
  QWidget* mainWidget = new QWidget(this);
  QHBoxLayout* layout = new QHBoxLayout();
  mainWidget->setLayout(layout);
  setCentralWidget(mainWidget);

  QTableView* tableView = new QTableView(this);
  tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
  LogModel* model = new LogModel({"TIMESTAMP", "LEVEL", "SUBSYSTEM", "CONTENT"});
  tableView->setModel(model);
  tableView->horizontalHeader()->setStretchLastSection(true);
  tableView->setItemDelegateForColumn(3, new ContentItemDelegate());
  layout->addWidget(tableView);


//    TailFileWatch* watch = new TailFileWatch("C:/untitled12/worker.log.gCOREw1.0");
      TailFileWatch* watch = new TailFileWatch("/mnt/winda/untitled12/worker.log.gCOREw1.0");
    OffsetLogParser* parser = new OffsetLogParser();
    connect(watch, &TailFileWatch::newLine, parser, &LogParser::parseLine);
    connect(parser, &LogParser::multiLineParsed, model, &LogModel::mergeLastRow);
    connect(parser, &LogParser::lineParsed, model, &LogModel::addRow);
  //  QElapsedTimer timer;
  //  timer.start();
//    for (long i = 0; i < 10000; i++) {
//      LogEntry entry = parser.parseLine("12:38:28 24/10/2017 Deb: [XML_:___] XmlDataLogger::log name='clientModuleInfo'");
//      model->addRow(entry);
//    }
  //  qDebug() << timer.elapsed()/1000.0;
}
void MainWindow::centerAndResize() {
    // get the dimension available on this screen
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QSize availableSize = desktopWidget->availableGeometry().size();
    int width = availableSize.width();
    int height = availableSize.height();
    qDebug() << "Available dimensions " << width << "x" << height;
    width *= 0.9; // 90% of the screen size
    height *= 0.9; // 90% of the screen size
    qDebug() << "Computed dimensions " << width << "x" << height;
    QSize newSize( width, height );

    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            newSize,
            desktopWidget->availableGeometry()
        )
    );
}
