// 本文件演示的函数与返回值类型：
// pow(double,double) -> double；pow(float,int/float) -> float；pow(long double, long double) -> long double（多重重载）
// sqrt(double) -> double；sqrtf/ sqrtl -> 对应浮点类型
// cbrt(double) -> double；cbrtf/ cbrtl -> 对应浮点类型
// hypot(double,double) -> double；有三参数重载 hypot(x,y,z) -> double；也有 float/long double 版本
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "pow(2, 10) = " << pow(2, 10) << "\n";   // 幂
    cout << "sqrt(2) = " << sqrt(2) << "\n";        // 平方根
    cout << "cbrt(27) = " << cbrt(27) << "\n";      // 立方根
    cout << "hypot(3, 4) = " << hypot(3, 4) << "\n";  // sqrt(x^2 + y^2)
    return 0;
}