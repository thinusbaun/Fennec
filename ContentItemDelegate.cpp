#include <QPainter>
#include <LogModel.h>
#include <QRegularExpression>
#include "ContentItemDelegate.h"

#include <QChar>

ContentItemDelegate::ContentItemDelegate()
{

}

void ContentItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QItemDelegate::paint(painter, option, index);
    bool isMultiline = index.data(MultiLineRole).toBool();
    if (isMultiline)
    {
//        painter->fillRect(option.rect, Qt::red);
        QRect rect = option.rect;
        rect.setLeft(rect.right()-10);
        painter->drawText(rect, Qt::AlignCenter, QChar(0x2026));
    }
}

void ContentItemDelegate::drawDisplay(QPainter *painter, const QStyleOptionViewItem &option, const QRect &rect, const QString &text) const
{
    QStringList textParts = text.split(QChar::LineSeparator,QString::SkipEmptyParts);
    if (textParts.size() > 1)
    {
        QItemDelegate::drawDisplay(painter, option, rect, textParts.first());
    }else
    {
        QItemDelegate::drawDisplay(painter, option, rect, text);
    }
}
