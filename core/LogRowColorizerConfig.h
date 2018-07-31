#ifndef LOGROWCOLORIZERCONFIG_H
#define LOGROWCOLORIZERCONFIG_H

#include <core_export.h>
#include <QColor>
#include <QJsonObject>
#include <QMap>
#include <QString>

class CORE_EXPORT LogRowColorizerConfig {
  using ValuesMapT = QMap<QString, QColor>;

 public:
  LogRowColorizerConfig();

  void read(const QJsonObject& json);
  void write(QJsonObject& json) const;

  QString partName() const;
  void setPartName(const QString& partName);

  QColor getColorForValue(const QString& value) const;
  void addColorForValue(const QString& value, const QColor& color);

 private:
  ValuesMapT mValues;
  QString mPartName;
};

#endif  // LOGROWCOLORIZERCONFIG_H
