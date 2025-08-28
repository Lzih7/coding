// 本文件演示的函数与返回值类型：
// exp/exp2/expm1(double) -> double；对应 expf/exp2f/expm1f -> float；expl/exp2l/expm1l -> long double
// log/log10/log2/log1p(double) -> double；也有 float/long double 版本
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "exp(1) = " << exp(1) << "\n";         // e^x
    cout << "expm1(1) = " << expm1(1) << "\n";       // e^x - 1，避免精度损失
    cout << "log(E) = " << log(exp(1)) << "\n";       // 自然对数
    cout << "log1p(1e-9) = " << log1p(1e-9) << "\n"; // log(1+x)

    cout << "log10(1000) = " << log10(1000) << "\n"; // 10 为底
    cout << "log2(8) = " << log2(8) << "\n";         // 2 为底

    cout << "exp2(10) = " << exp2(10) << "\n";       // 2^x
    return 0;
}