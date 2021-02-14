#include "plainbutton.h"
#include <QStyle>
#include <QStyleOptionButton>

PlainButton::PlainButton(QWidget *parent) : QAbstractButton(parent)
{
    j::LimitSize(this, 80, 24);
}

PlainButton::PlainButton(const QString &text, QWidget *parent) : PlainButton(parent)
{
    setText(text);
}

void PlainButton::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setFont(font());

    bool contains = QRect(0, 0, width(), height()).contains(mapFromGlobal(cursor().pos()));
    QColor& color = (isDown() ? mMouseDownColor : (contains ? mMouseOverColor : mNormalColor));
    QRect centralRect(mBorderSize, mBorderSize, width() - 2 * mBorderSize, height() - 2 * mBorderSize);

    p.fillRect(centralRect, color);
    p.drawText(centralRect, Qt::AlignCenter | Qt::AlignVCenter, text());
    j::DrawRecFrame(&p, 0, 0, width(), height(), mBorderSize, mBorderColor);
}
