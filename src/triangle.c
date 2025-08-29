
#include <math.h>
#include <stdio.h>

/*
 * 求三角形面积函数area
 * 参数说明：
 *      - a、b、c都是三角形的边长。
 * 返回值说明：
 *      - 如果a、b、c能构成三角形，则返回面积。
 *      - 否则，返回任意负值。
 */
double area(double a, double b, double c)
{
    // TODO
    double s, area=-1;
    if (a + b > c && a + c > b && b + c > a)
    {
        s = (a + b + c) / 2.0;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
    }
    return area;
    // END OF TODO
}

int main()
{
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    double res = area(a, b, c);
    if (res < 0)
        printf("invalid");
    else
        printf("%.2lf", res);
}