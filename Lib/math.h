#pragma once

#include <QVector>

namespace j {
    inline int Gcd(int a, int b) {  //得到两个数的最大公因数
        int absA = qMax(qAbs(a), qAbs(b));
        int absB = qMin(qAbs(a), qAbs(b));
        return absB == 0 ? absA : Gcd(b, a % b);
    }
    inline int Gcd(const QVector<int> &vValues, int n = -1) {    //得到许多数的最大公因数
        if(n == -1)
            n = vValues.size();
        return (n == 1 ? vValues[0] : Gcd(vValues[n - 1], Gcd(vValues, n - 1)));
    }
    inline int Lcm(int a, int b) {  //得到两个数的最小公倍数
        if(a == 0 || b == 0)
            return 0;
        return qAbs(a / Gcd(a, b) * b);
    }
    inline int Lcm(const QVector<int> &vValues, int n = -1) {    //得到许多数的最小公倍数
        if(n == -1)
            n = vValues.size();
        if(vValues[n - 1] == 0)
            return 0;
        return (n == 1 ? vValues[0] : Lcm(vValues[n - 1], Lcm(vValues, n - 1)));
    }
}
