#include <stdio.h>

/*
 * 利用斐波那契数列求黄金分割比例
 *
 * 参数说明：
 *      - n：int, 斐波那契数列的项数
 * 返回值说明：
 *      - double，黄金分割比例
 *
 * 提示：斐波那契数列每项的值都是整数
 * 注意：不能也不需要用递归方法
 */
double phi(int n)
{
    // TODO
    int dp[n];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return 1.0 * dp[n - 2] / dp[n - 1];
    // END OF TODO
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%.5lf\n", phi(n));

    return 0;
}
