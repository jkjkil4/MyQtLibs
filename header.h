#ifndef HEADER_H
#define HEADER_H

#include <QCoreApplication>

#define repeat(i, n) for(int i = 0; i < n; i++)
#define APP_DIR QCoreApplication::applicationDirPath()

#define VAR_GET_FUNC(Func, var, Type) Type get##Func() const { return var; }
#define VAR_SET_FUNC(Func, var, Type, Const, Quote) void set##Func(Const Type Quote __##var##__) { var = __##var##__; }
#define VAR_FUNC(Func, var, Type, Const, Quote) VAR_GET_FUNC(Func, var, Type) VAR_SET_FUNC(Func, var, Type, Const, Quote)

#endif // HEADER_H
