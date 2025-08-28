// 本文件演示的函数与返回值类型：
// sinh/cosh/tanh(double) -> double；也有 float/long double 版本
// asinh/acosh/atanh(double) -> double；也有 float/long double 版本
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "sinh(1) = " << sinh(1) << "\n";
    cout << "cosh(1) = " << cosh(1) << "\n";
    cout << "tanh(1) = " << tanh(1) << "\n";

    cout << "asinh(1) = " << asinh(1) << "\n";
    cout << "acosh(2) = " << acosh(2) << "\n";
    cout << "atanh(0.5) = " << atanh(0.5) << "\n";
    return 0;
}