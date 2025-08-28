// 本文件说明：
// M_PI 等宏常量（若定义）为 double 类型常量宏；非函数无“返回值”。
// C++20 <numbers> 中 std::numbers::pi_v<T> 为变量模板，类型为 T；std::numbers::pi 为 long double 常量。
#include <iostream>
#include <cmath>
using namespace std;

int main() {
#ifdef M_PI
    cout << "M_PI = " << M_PI << "\n";
#else
    cout << "M_PI not defined by <cmath> in strict modes, you can define _USE_MATH_DEFINES before <cmath> on MSVC or use std::numbers::pi in C++20." << "\n";
#endif

#if __cpp_lib_math_constants
    // C++20 提供 std::numbers 常量
    // 需要: #include <numbers>
    cout << "C++20 has <numbers> constants like std::numbers::pi, e, sqrt2, etc." << "\n";
#endif

    return 0;
}