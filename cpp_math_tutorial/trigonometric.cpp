// 本文件演示的函数与返回值类型：
// sin/ cos/ tan(double) -> double；对应的 sinf/cosf/tanf -> float；sinl/cosl/tanl -> long double
// asin/ acos/ atan(double) -> double；也有 float/long double 版本
// atan2(double,double) -> double；atan2f/atan2l -> 对应浮点类型
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double rad = M_PI / 6; // 30 度
    cout << "sin(30°) = " << sin(rad) << "\n";
    cout << "cos(30°) = " << cos(rad) << "\n";
    cout << "tan(30°) = " << tan(rad) << "\n";

    cout << "asin(0.5) = " << asin(0.5) << "\n";
    cout << "acos(0.8660254038) = " << acos(0.8660254038) << "\n";
    cout << "atan(0.577350269) = " << atan(0.577350269) << "\n";

    // 双参数反正切，考虑象限
    cout << "atan2(1, 1) = " << atan2(1, 1) << "\n"; // 45° -> PI/4
    return 0;
}