#pragma once

#include <Lib/Item/chequereddelegate.h>
#include <Lib/paint.h>

class DTextDelegate : public ChequeredDelegate
{
public:
    DTextDelegate(QObject *parent = nullptr);

    void paint(QPainter *p, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    VAR_FUNC(Text1PointSize, mText1PointSize, int, , )
    VAR_FUNC(Text2PointSize, mText2PointSize, int, , )
    VAR_FUNC(Text1Color, mText1Color, QColor, , )
    VAR_FUNC(Text2Color, mText2Color, QColor, , )
    VAR_FUNC(Height, mHeight, int, , )
    VAR_FUNC(Margin, mMargin, int, , )
    VAR_FUNC(Spacing, mSpacing, int, , )

private:
    int mText1PointSize = 11;
    int mText2PointSize = 7;

    QColor mText1Color = QColor(70, 40, 70);
    QColor mText2Color = Qt::darkGray;

    int mHeight = 46;
    int mMargin = 3;
    int mSpacing = 2;
};
