# C++ Math 库深度讲解

本文件夹包含了对 C++ `<cmath>` 库的全面讲解，包括各种数学函数的使用方法和实例。

## 文件结构

- `basic_functions.cpp` - 基础数学函数
- `trigonometric.cpp` - 三角函数
- `exponential_logarithmic.cpp` - 指数和对数函数
- `rounding_functions.cpp` - 取整函数
- `power_functions.cpp` - 幂函数
- `hyperbolic.cpp` - 双曲函数
- `special_functions.cpp` - 特殊数学函数
- `comparison_functions.cpp` - 比较函数
- `constants.cpp` - 数学常数
- `examples_demo.cpp` - 综合应用实例

## 编译和运行

使用 g++ 编译任意文件：
```bash
g++ -o output_name file_name.cpp -std=c++11
./output_name
```

注意：某些函数需要链接数学库：
```bash
g++ -o output_name file_name.cpp -lm -std=c++11
```