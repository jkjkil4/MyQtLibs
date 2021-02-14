#include "dtextdelegate.h"

DTextDelegate::DTextDelegate(QObject *parent) : ChequeredDelegate(parent) {}

void DTextDelegate::paint(QPainter *p, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    ChequeredDelegate::paint(p, option, index);

    p->save();

    QString text1 = index.data(Qt::UserRole).toString();
    QString text2 = index.data(Qt::UserRole + 1).toString();
    QRect rect = option.rect;
    rect.setX(rect.x() + mMargin);
    rect.setY(rect.y() + mMargin);
    rect.setWidth(rect.width() - mMargin);
    rect.setHeight(rect.height() - mMargin);

    QRect tmpRect;

    j::SetPointSize(p, mText1PointSize);
    p->setPen(mText1Color);
    p->drawText(rect, Qt::AlignLeft | Qt::AlignTop, text1, &tmpRect);
    rect.setY(rect.y() + tmpRect.height() + mSpacing);

    j::SetPointSize(p, mText2PointSize);
    p->setPen(mText2Color);
    p->drawText(rect, Qt::AlignLeft | Qt::AlignTop, text2);

    p->restore();
}

QSize DTextDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QSize size = ChequeredDelegate::sizeHint(option, index);
    return QSize(size.width(),  mHeight);
}
