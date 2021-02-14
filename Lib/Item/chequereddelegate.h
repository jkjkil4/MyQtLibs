#pragma once

#include <QItemDelegate>
#include <QPainter>

#include "Lib/header.h"

class ChequeredDelegate : public QItemDelegate
{
public:
    ChequeredDelegate(QObject *parent = nullptr);

    virtual void paint(QPainter *p, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

    void setBackgroundColor(QColor col1, QColor col2) { mBackgroundColor1 = col1; mBackgroundColor2 = col2; }
    VAR_FUNC(backgroundColor1, setBackgroundColor1, mBackgroundColor1, QColor, , )
    VAR_FUNC(backgroundColor2, setBackgroundColor2, mBackgroundColor2, QColor, , )

private:
    QColor mBackgroundColor1 = QColor(245, 245, 245);
    QColor mBackgroundColor2 = QColor(235, 235, 235);
    QColor mMouseOverColor = QColor(227, 227, 255);
    QColor mSelectedColor = QColor(210, 210, 250);
};
