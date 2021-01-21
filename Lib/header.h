#ifndef HEADER_H
#define HEADER_H

#include <QWidget>

#define repeat(Type, i, n) for(Type i = 0; i < n; i++)
#define SET_PTR(ptr, v) if(ptr) *ptr = v
#define APP_DIR QCoreApplication::applicationDirPath()

#define VAR_GET_FUNC(Func, var, Type) Type get##Func() const { return var; }
#define VAR_SET_FUNC(Func, var, Type, Const, Quote) void set##Func(Const Type Quote __##var##__) { var = __##var##__; }
#define VAR_FUNC(Func, var, Type, Const, Quote) VAR_GET_FUNC(Func, var, Type) VAR_SET_FUNC(Func, var, Type, Const, Quote)

namespace j {
    template<typename T>
    inline void SafeDelete(T *&p) {
        if(p) {
            delete p;
            p = nullptr;
        }
    }

    template<typename T>
    inline void SafeDeleteArray(T *&p) {
        if(p) {
            delete[] p;
            p = nullptr;
        }
    }

    inline void LimitWidth(QWidget *widget, int width) {
        widget->setMinimumWidth(width);
        widget->setMaximumWidth(width);
    }
    inline void LimitHeight(QWidget *widget, int height) {
        widget->setMinimumHeight(height);
        widget->setMaximumHeight(height);
    }
    inline void LimitSize(QWidget *widget, int w, int h) {
        widget->setMinimumSize(w, h);
        widget->setMaximumSize(w, h);
    }
    inline void LimitSize(QWidget *widget, QSize size) {
        widget->setMinimumSize(size);
        widget->setMaximumSize(size);
    }
}

#endif // HEADER_H
