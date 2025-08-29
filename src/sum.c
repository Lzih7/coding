/*有如下定义：

【定义1】假设有正整数n和f（f小于n），如果n能够被f整除，那么f就是n的一个因子。

【定义2】正整数n的因子范围包括1但不包括n本身。

基于上述定义，假设有两个正整数a和b（a小于b），如果a的所有因子之和等于b，且b的所有因子等于a，那么二元组(a,b)就被称为是“亲密数对”。例如，(220,284)就是一对亲密数对。

已定义好函数 sum_of_factors，其功能是求正整数 n 的所有因子之和。函数原型为： unsigned sum_of_factors(unsigned n);

根据上述描述，编写程序，要求如下： 完善下面的 main() 函数，其功能是：从键盘输入一个正整数n（<=20000），然后调用函数 sum_of_factors 找出 1~n 之间的所有亲密数对。 输出形式为：(a,b)(c,d)…。所有输出都在一行。提示：3000以内有三对。

【（a,b)中，仅仅认为a<=n，b不做限制】（此为考场临时更正题目所加）

提示：若使用双重嵌套循环（for里面再套一个for，while里面再套一个while之类）会导致超时且本题成绩为0，需另寻他路，*/
#include <stdio.h>

unsigned sum_of_factors(unsigned n);
void Solution(unsigned n);
int main()
{
    unsigned n;
    scanf("%d", &n);
    Solution(n);

    return 0;
}
unsigned sum_of_factors(unsigned n)
{
    int ret = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            ret += i;
    }
    return ret;
}
void Solution(unsigned n)
{
    for (int i = 1; i <= n; i++)
    {
        int num = sum_of_factors(i);
        if (i == sum_of_factors(num) && num > i)
        {
            printf("(%d,%d) ", i, num);
        }
    }
    return;
}