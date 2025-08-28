// 本文件演示的函数与返回值类型：
// isnan(double) -> int（C宏）/ bool（C++重载）；对 float/long double 有对应重载
// isfinite(double) -> int/ bool（同上）
// isinf(double) -> int/ bool（同上）
// fpclassify(x) -> int（返回FP_NAN/FP_INFINITE/FP_ZERO/FP_SUBNORMAL/FP_NORMAL之一）
// fmax(double,double) -> double；fmin(double,double) -> double（也有 float/long double 版本）
// nextafter(double,double) -> double；nexttoward(long double,long double) -> long double；有对应重载
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 0.0/0.0; // NaN
    cout << boolalpha;
    cout << "isnan(NaN) = " << isnan(a) << "\n";
    cout << "isfinite(1.0) = " << isfinite(1.0) << "\n";
    cout << "isinf(1.0/0.0) = " << isinf(1.0/0.0) << "\n";
    cout << "fpclassify(0.0) = " << fpclassify(0.0) << "\n";

    cout << "fmax(2.3, 4.5) = " << fmax(2.3, 4.5) << "\n";
    cout << "fmin(2.3, 4.5) = " << fmin(2.3, 4.5) << "\n";
    cout << "nextafter(1.0, 2.0) = " << nextafter(1.0, 2.0) << "\n";
    cout << "nexttoward(1.0L, 2.0L) = " << nexttoward(1.0L, 2.0L) << "\n";
    return 0;
}