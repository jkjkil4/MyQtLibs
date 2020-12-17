#ifndef HEADER_H
#define HEADER_H

#include <QCoreApplication>
#include <QFont>
#include <QPainter>

#define repeat(i, n) for(int i = 0; i < n; i++)
#define SET_PTR(ptr, v) if(ptr) *ptr = v
#define APP_DIR QCoreApplication::applicationDirPath()

#define VAR_GET_FUNC(Func, var, Type) Type get##Func() const { return var; }
#define VAR_SET_FUNC(Func, var, Type, Const, Quote) void set##Func(Const Type Quote __##var##__) { var = __##var##__; }
#define VAR_FUNC(Func, var, Type, Const, Quote) VAR_GET_FUNC(Func, var, Type) VAR_SET_FUNC(Func, var, Type, Const, Quote)

namespace j {

template<typename T>inline void SetPointSize(T *t, int pointSize) {
    QFont font = t->font();
    font.setPointSize(pointSize);
    t->setFont(font);
}

inline void DrawText(QPainter &p, int x, int y, int flags, QString str,
                      int xLimit = -1, int yLimit = -1, QRect *pRect = nullptr)
{
    //字体
    QFontMetrics fm(p.font());
    QRect rec = fm.boundingRect(QRect(0, 0, INT_MAX, INT_MAX), Qt::TextFlag(), str);
    //大小
    int w = rec.width(), h = rec.height();
    if(xLimit != -1 && w > xLimit)
        w = xLimit;
    if(yLimit != -1 && h > yLimit)
        h = yLimit;
    //判断
    x -= w/2;
    y -= h/2;
    if(flags & Qt::AlignRight)
        x -= w/2;
    if(flags & Qt::AlignLeft)
        x += w/2;
    if(flags & Qt::AlignBottom)
        y -= h/2;
    if(flags & Qt::AlignTop)
        y += h/2;
    //字符串所占的像素宽度,高度
    QRect r = QRect(x, y, w, h);
    SET_PTR(pRect, r);
    //绘制
    p.drawText(r, flags, str);
}
inline void DrawText(QPainter &p, QPoint pos, int flags, QString str,
                      int xLimit = -1, int yLimit = -1, QRect *pRect = nullptr)
{
    DrawText(p, pos.x(), pos.y(), flags, str, xLimit, yLimit, pRect);
}

}

#endif // HEADER_H
