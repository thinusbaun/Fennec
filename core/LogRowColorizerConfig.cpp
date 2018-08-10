#include "LogRowColorizerConfig.h"
#include <QDebug>
#include <QJsonArray>

LogRowColorizerConfig::LogRowColorizerConfig() {}

void LogRowColorizerConfig::read(const QJsonObject &json) {
  mPartName = json["partName"].toString();
  QJsonArray valuesArray = json["values"].toArray();
  for (auto it = valuesArray.constBegin(); it != valuesArray.constEnd(); it++) {
    auto valueObj = it->toObject();
    auto match = valueObj["match"].toString();
    QColor color;
    color.setNamedColor(valueObj["color"].toString());
    mValues.insert(match, color);
    qDebug() << match << color;
  }
}

void LogRowColorizerConfig::write(QJsonObject &json) const {
  QJsonArray valuesArray;
  for (auto it = mValues.constBegin(); it != mValues.constEnd(); it++) {
    QJsonObject valueObject;
    valueObject["match"] = it.key();
    valueObject["color"] = it.value().name();
    valuesArray.append(valueObject);
  }
  json["values"] = valuesArray;
  json["partName"] = mPartName;
}

QString LogRowColorizerConfig::partName() const { return mPartName; }

void LogRowColorizerConfig::setPartName(const QString &partName) {
  mPartName = partName;
}

QColor LogRowColorizerConfig::getColorForValue(const QString &value) const {
  if (mValues.contains(value)) {
    return mValues[value];
  } else {
    return "transparent";
  }
}

void LogRowColorizerConfig::addColorForValue(const QString &value,
                                             const QColor &color) {
  mValues.insert(value, color);
}
