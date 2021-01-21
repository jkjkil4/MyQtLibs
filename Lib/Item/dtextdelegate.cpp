#include "dtextdelegate.h"

DTextDelegate::DTextDelegate(QObject *parent) : ChequeredDelegate(parent) {}

void DTextDelegate::paint(QPainter *p, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    ChequeredDelegate::paint(p, option, index);

    p->save();

    QString text1 = index.data(Qt::UserRole).toString();
    QString text2 = index.data(Qt::UserRole + 1).toString();
    QRect rect = option.rect;
    rect.setX(rect.x() + margin);
    rect.setY(rect.y() + margin);
    rect.setWidth(rect.width() - margin);
    rect.setHeight(rect.height() - margin);

    QRect tmpRect;

    j::SetPointSize(p, text1PointSize);
    p->setPen(text1Color);
    p->drawText(rect, Qt::AlignLeft | Qt::AlignTop, text1, &tmpRect);
    rect.setY(rect.y() + tmpRect.height() + spacing);

    j::SetPointSize(p, text2PointSize);
    p->setPen(text2Color);
    p->drawText(rect, Qt::AlignLeft | Qt::AlignTop, text2);

    p->restore();
}

QSize DTextDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QSize size = ChequeredDelegate::sizeHint(option, index);
    return QSize(size.width(),  height);
}
