#include "chequereddelegate.h"

ChequeredDelegate::ChequeredDelegate(QObject *parent) : QItemDelegate(parent) {}

void ChequeredDelegate::paint(QPainter *p, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if(index.isValid()) {
        QColor color = (option.state.testFlag(QStyle::State_Selected)
                        ? mSelectedColor
                        : option.state.testFlag(QStyle::State_MouseOver)
                            ? mMouseOverColor
                            : (index.row() % 2 ? mBackgroundColor2 : mBackgroundColor1));
        p->fillRect(option.rect, color);
    }
}
