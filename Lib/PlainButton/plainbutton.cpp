#include "plainbutton.h"

PlainButton::PlainButton(QWidget *parent) : QAbstractButton(parent)
{
    j::LimitSize(this, 80, 24);
}

PlainButton::PlainButton(const QString &text, QWidget *parent) : QAbstractButton(parent)
{
    j::LimitSize(this, 80, 24);
    setText(text);
}

void PlainButton::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setFont(font());

    bool contains = QRect(0, 0, width(), height()).contains(mapFromGlobal(cursor().pos()));
    QColor& color = (isDown() ? mouseDownColor : (contains ? mouseOverColor : normalColor));
    QRect centralRect(borderSize, borderSize, width() - 2 * borderSize, height() - 2 * borderSize);

    p.fillRect(centralRect, color);
    p.drawText(centralRect, Qt::AlignCenter | Qt::AlignVCenter, text());
    j::DrawRecFrame(&p, 0, 0, width(), height(), borderSize, borderColor);
}
