// 本文件演示的函数与返回值类型：
// erf/erfc(double) -> double；有 float/long double 版本
// tgamma(double) -> double；lgamma(double) -> double（注意lgamma返回log(Gamma(x))）
// copysign(double,double) -> double；有 float/long double 版本
// signbit(double) -> int（C宏）/ bool（C++实现），也有其它浮点重载
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "erf(1) = " << erf(1) << "\n";     // 误差函数
    cout << "erfc(1) = " << erfc(1) << "\n";   // 互补误差函数
    cout << "tgamma(5) = " << tgamma(5) << "\n"; // Gamma 函数 (4!)
    cout << "lgamma(5) = " << lgamma(5) << "\n"; // Gamma 的自然对数

    // 符号与乘积
    cout << "copysign(3.0, -0.0) = " << copysign(3.0, -0.0) << "\n";
    cout << "signbit(-0.0) = " << signbit(-0.0) << "\n";
    return 0;
}