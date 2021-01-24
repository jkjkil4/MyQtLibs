#pragma once

#include <QItemDelegate>
#include <QPainter>

#include "Lib/header.h"

class ChequeredDelegate : public QItemDelegate
{
public:
    ChequeredDelegate(QObject *parent = nullptr);

    virtual void paint(QPainter *p, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

    void setBackgroundColor(QColor col1, QColor col2) { backgroundColor1 = col1; backgroundColor2 = col2; }
    VAR_FUNC(BackgroundColor1, backgroundColor1, QColor, , )
    VAR_FUNC(BackgroundColor2, backgroundColor2, QColor, , )

private:
    QColor backgroundColor1 = QColor(245, 245, 245);
    QColor backgroundColor2 = QColor(235, 235, 235);
    QColor mouseOverColor = QColor(227, 227, 255);
    QColor selectedColor = QColor(210, 210, 250);
};
