#ifndef PLAINBUTTON_H
#define PLAINBUTTON_H

#include <QAbstractButton>

#include "Lib/paint.h"

class PlainButton : public QAbstractButton
{
protected:
    void paintEvent(QPaintEvent *) override;

public:
    explicit PlainButton(QWidget *parent = nullptr) : QAbstractButton(parent) {}
    explicit PlainButton(const QString& text, QWidget *parent = nullptr) : QAbstractButton(parent) { setText(text); }

    VAR_FUNC(BorderColor, borderColor, QColor, , )
    VAR_FUNC(BorderSize, borderSize, int, , )

    VAR_FUNC(NormalColor, normalColor, QColor, , )
    VAR_FUNC(MouseOverColor, mouseOverColor, QColor, , )
    VAR_FUNC(MouseDownColor, mouseDownColor, QColor, , )

private:
    QColor borderColor = QColor(120, 120, 120);
    int borderSize = 1;

    QColor normalColor = QColor(250, 250, 250);
    QColor mouseOverColor = QColor(253, 253, 253);
    QColor mouseDownColor = QColor(239, 239, 239);
};

#endif // PLAINBUTTON_H
