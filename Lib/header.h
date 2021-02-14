#pragma once

#include <QWidget>

#define repeat(Type, i, n) for(Type i = 0; i < n; i++)
#define SET_PTR(ptr, v) if(ptr) *ptr = v
#define APP_DIR QCoreApplication::applicationDirPath()

#define VAR_GET_FUNC(Getter, var, Type) \
    Type Getter() const { return var; }
#define VAR_SET_FUNC(Setter, var, Type, Const, Quote) \
    void Setter(Const Type Quote __##var##__) { var = __##var##__; }
#define VAR_FUNC(Getter, Setter, var, Type, Const, Quote) \
    VAR_GET_FUNC(Getter, var, Type) VAR_SET_FUNC(Setter, var, Type, Const, Quote)

#define VAR_SET_FUNC_USER(Setter, var, Type, User, Const, Quote) \
    void Setter(Const Type Quote __##var##__) { var = __##var##__; User; }
#define VAR_FUNC_USER(Getter, Setter, var, Type, User, Const, Quote) \
    VAR_GET_FUNC(Getter, var, Type) VAR_SET_FUNC_USER(Setter, var, Type, User, Const, Quote)

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
