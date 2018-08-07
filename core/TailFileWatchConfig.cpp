#include "TailFileWatchConfig.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QVariant>

TailFileWatchConfig::TailFileWatchConfig() {}

void TailFileWatchConfig::read(const QJsonObject& json) {
  if (json.contains("exec_path")) {
    mProcessPath = json["exec_path"].toString();
  }
  if (json.contains("args")) {
    auto jsonValues = json["args"].toArray().toVariantList();
    for (const auto& value : jsonValues) {
      mArgs << value.toString();
    }
  }
}

void TailFileWatchConfig::write(QJsonObject& json) const {
  if (!mProcessPath.isEmpty()) {
    json["exec_path"] = mProcessPath;
  }
  if (!mArgs.empty()) {
    QJsonArray array = QJsonArray::fromStringList(mArgs);
    json["args"] = array;
  }
}

QString TailFileWatchConfig::processPath() const { return mProcessPath; }

void TailFileWatchConfig::setProcessPath(const QString& processPath) {
  mProcessPath = processPath;
}

QStringList TailFileWatchConfig::args() const { return mArgs; }

void TailFileWatchConfig::setArgs(const QStringList& args) { mArgs = args; }
