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

    VAR_FUNC_USER(borderColor, setBorderColor, mBorderColor, QColor, update(), , )
    VAR_FUNC_USER(borderSize, setBorderSize, mBorderSize, int, update(), , )

    VAR_FUNC_USER(normalColor, setNormalColor, mNormalColor, QColor, update(), , )
    VAR_FUNC_USER(mouseOverColor, setMouseOverColor, mMouseOverColor, QColor, update(), , )
    VAR_FUNC_USER(mouseDownColor, setMouseDownColor, mMouseDownColor, QColor, update(), , )

private:
    QColor mBorderColor = QColor(120, 120, 120);
    int mBorderSize = 1;

    QColor mNormalColor = QColor(246, 246, 246);
    QColor mMouseOverColor = QColor(255, 255, 255);
    QColor mMouseDownColor = QColor(237, 237, 237);
};
