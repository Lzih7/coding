# 类
## 成员分类
1. public：任意访问
2. private：类的内部可访问
3. protected：类内部以及派生类内部可访问
## 虚函数
- 在派生类中可被重写
## 域解析运算符(::)
```cpp
class MathUtils {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

// 使用方式一：通过类名直接调用（推荐）
int result1 = MathUtils::add(3, 5);

// 使用方式二：通过实例调用（语法上允许，但不推荐）
MathUtils utils;
int result2 = utils.add(3, 5);           // 可以，但没必要
int result3 = utils::add(3, 5);          // 也可以（等价）
```