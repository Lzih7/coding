// 本文件演示的函数与返回值类型：
// fabs(double) -> double；fabsf(float) -> float；fabsl(long double) -> long double
// abs(int) -> int；std::abs(double/float/long double) 按重载返回相应类型
// fmod(double, double) -> double；fmodf(float, float) -> float；fmodl(long double, long double) -> long double
// remainder(double, double) -> double；remainderf/ remainderl -> 对应浮点类型
// fma(double,double,double) -> double；fmaf(float,float,float) -> float；fmal(long double,long double,long double) -> long double
// std::min/std::max 为模板，返回T（参数类型的共同类型）
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "fabs(-3.14) = " << fabs(-3.14) << "\n";          // 绝对值（double）
    cout << "abs(-5) = " << abs(-5) << "\n";                 // 绝对值（int）
    cout << "fmod(7.5, 2.3) = " << fmod(7.5, 2.3) << "\n";    // 浮点数取模
    cout << "remainder(7.5, 2.3) = " << remainder(7.5, 2.3) << "\n"; // IEEE 余数
    cout << "fma(2.0, 3.0, 4.0) = " << fma(2.0, 3.0, 4.0) << "\n";   // Fused multiply-add

    // min/max with <algorithm> 也很常用
    cout << "min(3, 5) = " << min(3, 5) << ", max(3, 5) = " << max(3, 5) << "\n";
    return 0;
}