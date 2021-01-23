#ifndef PAINT_H
#define PAINT_H

#include <QPainter>
#include "header.h"

namespace j {
    template<typename T>inline void SetPointSize(T *t, int pointSize) {
        QFont font = t->font();
        font.setPointSize(pointSize);
        t->setFont(font);
    }
    template<typename T>inline void SetFamily(T *t, const QString& family) {
        QFont font = t->font();
        font.setFamily(family);
        t->setFont(font);
    }
    template<typename T>inline void SetBold(T *t, bool bold) {
        QFont font = t->font();
        font.setBold(bold);
        t->setFont(font);
    }

    inline void DrawText(QPainter *p, int x, int y, int flags, QString str,
                          int xLimit = -1, int yLimit = -1, QRect *pRect = nullptr)
    {
        //字体
        QFontMetrics fm(p->font());
        QRect rec = fm.boundingRect(QRect(0, 0, INT_MAX, INT_MAX), Qt::TextFlag(), str);
        //大小
        int w = rec.width(), h = rec.height();
        if(xLimit != -1 && w > xLimit)
            w = xLimit;
        if(yLimit != -1 && h > yLimit)
            h = yLimit;
        //判断
        x -= w / 2;
        y -= h / 2;
        if(flags & Qt::AlignRight)
            x -= w / 2;
        if(flags & Qt::AlignLeft)
            x += w / 2;
        if(flags & Qt::AlignBottom)
            y -= h / 2;
        if(flags & Qt::AlignTop)
            y += h / 2;
        //字符串所占的像素宽度,高度
        QRect r = QRect(x, y, w, h);
        SET_PTR(pRect, r);
        //绘制
        p->drawText(r, flags, str);
    }
    inline void DrawText(QPainter *p, QPoint pos, int flags, QString str,
                          int xLimit = -1, int yLimit = -1, QRect *pRect = nullptr)
    {
        DrawText(p, pos.x(), pos.y(), flags, str, xLimit, yLimit, pRect);
    }

    inline void DrawRecFrame(QPainter* p, int x, int y, int w, int h, int size, QColor c){
        p->fillRect(x, y, w, size, c);  //顶部
        p->fillRect(x, y + size, size, h - 2 * size, c);  //左侧
        p->fillRect(x + w - size, y + size, size, h - 2 * size, c);  //右侧
        p->fillRect(x, y + h - size, w, size, c);  //底部
    }
}

#endif // PAINT_H
