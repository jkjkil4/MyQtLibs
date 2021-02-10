#pragma once

#include <QAbstractButton>

#include "Lib/paint.h"

class PlainButton : public QAbstractButton
{
protected:
    void paintEvent(QPaintEvent *) override;

public:
    explicit PlainButton(QWidget *parent = nullptr);
    explicit PlainButton(const QString &text, QWidget *parent = nullptr);

    VAR_FUNC_USER(BorderColor, borderColor, QColor, update(), , )
    VAR_FUNC_USER(BorderSize, borderSize, int, update(), , )

    VAR_FUNC_USER(NormalColor, normalColor, QColor, update(), , )
    VAR_FUNC_USER(MouseOverColor, mouseOverColor, QColor, update(), , )
    VAR_FUNC_USER(MouseDownColor, mouseDownColor, QColor, update(), , )

private:
    QColor borderColor = QColor(120, 120, 120);
    int borderSize = 1;

    QColor normalColor = QColor(246, 246, 246);
    QColor mouseOverColor = QColor(255, 255, 255);
    QColor mouseDownColor = QColor(237, 237, 237);
};
