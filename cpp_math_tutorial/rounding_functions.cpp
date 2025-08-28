// 本文件演示的函数与返回值类型：
// floor/ceil/trunc/round(double) -> double；对应 float/long double 版本返回相应类型
// lround(double) -> long（MSVC/MinGW 上为 long long 时请参考实现）；llround(double) -> long long
// nearbyint(double) -> double（不改变当前舍入模式的flag）
// modf(double, double*) -> double（返回小数部分，通过指针返回整数部分）；有 float/long double 版本
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "floor(3.7) = " << floor(3.7) << "\n";   // 向下取整
    cout << "ceil(3.1) = " << ceil(3.1) << "\n";     // 向上取整
    cout << "trunc(-3.7) = " << trunc(-3.7) << "\n"; // 截断
    cout << "round(3.5) = " << round(3.5) << "\n";   // 四舍五入到最近整数
    cout << "lround(3.5) = " << lround(3.5) << "\n"; // 返回 long
    cout << "nearbyint(2.5) = " << nearbyint(2.5) << "\n"; // 遵循当前舍入模式

    double i, frac = modf(3.14, &i); // 分离整数与小数部分
    cout << "modf(3.14): int=" << i << ", frac=" << frac << "\n";

    return 0;
}