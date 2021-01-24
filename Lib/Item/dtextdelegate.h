#pragma once

#include <Lib/Item/chequereddelegate.h>
#include <Lib/paint.h>

class DTextDelegate : public ChequeredDelegate
{
public:
    DTextDelegate(QObject *parent = nullptr);

    void paint(QPainter *p, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    VAR_FUNC(Text1PointSize, text1PointSize, int, , )
    VAR_FUNC(Text2PointSize, text2PointSize, int, , )
    VAR_FUNC(Text1Color, text1Color, QColor, , )
    VAR_FUNC(Text2Color, text2Color, QColor, , )
    VAR_FUNC(Height, height, int, , )
    VAR_FUNC(Margin, margin, int, , )
    VAR_FUNC(Spacing, spacing, int, , )

private:
    int text1PointSize = 11;
    int text2PointSize = 7;

    QColor text1Color = QColor(70, 40, 70);
    QColor text2Color = Qt::darkGray;

    int height = 46;
    int margin = 3;
    int spacing = 2;
};
