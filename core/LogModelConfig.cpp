#include "LogModelConfig.h"
#include <QJsonArray>
#include <QVariant>

LogModelConfig::LogModelConfig() {}

void LogModelConfig::read(const QJsonObject &json) {
  if (json.contains("limitRows")) {
    mLimitRows = json["limitRows"].toInt(-1);
  }
  auto headers = json["headers"].toArray().toVariantList();
  for (const auto &header : headers) {
    mHeaders << header.toString();
  }
}

void LogModelConfig::write(QJsonObject &json) const {
  json["limitRows"] = mLimitRows;
  QJsonArray array = QJsonArray::fromStringList(mHeaders);
  json["headers"] = array;
}

QStringList LogModelConfig::headers() const { return mHeaders; }

void LogModelConfig::setHeaders(const QStringList &headers) {
  mHeaders = headers;
}

int LogModelConfig::limitRows() const { return mLimitRows; }

void LogModelConfig::setLimitRows(int limitRows) { mLimitRows = limitRows; }
