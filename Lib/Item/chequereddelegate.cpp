#include "chequereddelegate.h"

ChequeredDelegate::ChequeredDelegate(QObject *parent) : QItemDelegate(parent) {}

void ChequeredDelegate::paint(QPainter *p, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if(index.isValid()) {
        QColor color = (option.state.testFlag(QStyle::State_Selected)
                        ? selectedColor
                        : option.state.testFlag(QStyle::State_MouseOver)
                            ? mouseOverColor
                            : (index.row() % 2 ? backgroundColor2 : backgroundColor1));
        p->fillRect(option.rect, color);
    }
}
