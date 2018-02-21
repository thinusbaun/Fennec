#ifndef CONTENTITEMDELEGATE_H
#define CONTENTITEMDELEGATE_H

#include <QItemDelegate>
#include <QObject>
#include <core_export.h>

class CORE_EXPORT ContentItemDelegate : public QItemDelegate {
public:
  ContentItemDelegate();
  void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const override;

private:
  virtual void drawDisplay(QPainter *painter,
                           const QStyleOptionViewItem &option,
                           const QRect &rect,
                           const QString &text) const override;
};

#endif // CONTENTITEMDELEGATE_H
