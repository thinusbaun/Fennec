#include "ContentItemDelegate.h"
#include "LogModel.h"
#include "LogModelFactory.h"
#include "RegexLogParser.h"
#include "RegexLogParserFactory.h"
#include "TailFileWatch.h"
#include "TailFileWatchFactory.h"

#include "LogViewTabManager.h"
#include "SettingsProvider.h"

#include <QHeaderView>
#include <QTableView>

LogViewTabManager::LogViewTabManager(QTabWidget* widgetToManage,
                                     const QMap<QString, QVariant>& settings,
                                     SettingsProvider& settingsProvider,
                                     QObject* parent)
    : QObject(parent),
      mWidget(widgetToManage),
      mSettings(settings),
      mSettingsProvider(settingsProvider) {}

void LogViewTabManager::createViews() {
  QTableView* tableView = new QTableView();
  tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

  LogModelFactory factory(mSettingsProvider, this);
  LogModel* model = factory.create();
  tableView->setModel(model);
  tableView->horizontalHeader()->setStretchLastSection(true);
  tableView->setItemDelegateForColumn(
      model->columnCount(model->index(0, 0)) - 1, new ContentItemDelegate());

  TailFileWatchFactory watchFactory(mSettings, this);
  TailFileWatch* watch = watchFactory.create();

  RegexLogParserFactory parserFactory(mSettings, this);
  RegexLogParser* parser = parserFactory.create();

  connect(watch, &TailFileWatch::newLine, parser, &LogParser::parseLine);
  connect(parser, &LogParser::multiLineParsed, model, &LogModel::mergeLastRow);
  connect(parser, &LogParser::lineParsed, model, &LogModel::addRow);
  watch->openFile();
  mWidget->addTab(tableView, "File");
}
