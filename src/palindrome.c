#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(char *a, int n)
{
    char *l = a;
    char *r = a + n - 1;
    while (l < r)
    {
        if (*l != *r)
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main()
{
    char x[] = "aaccaa";
    int n = (sizeof(x) / sizeof(x[0])) - 1;
    printf(is_palindrome(x, n) ? "yes" : "no");

    return 0;
}