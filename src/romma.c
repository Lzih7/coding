#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*算法：从大到小，先填入最大的*/
int arr[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
char *s[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};  //注意s的类型
//建立数字和字符串的对应关系
char* intToRoman(int num) {
    // 为了容纳罗马数字结果，预估最多需要16字节空间，足够表示任意整数转换的罗马数字。
    char* s1 = (char*)malloc(sizeof(char) * 20);
    if (s1 == NULL) {
        return NULL; // 确保内存分配成功
    }

    // 初始化字符串为空
    s1[0] = '\0';

    // 用于追踪当前写入的位置
    char* p = s1;

    for (int i = 0; i < 13; i++) {
        while (num >= arr[i]) {
            num -= arr[i];
            // 将当前罗马数字拷贝到 `p` 指向的位置
            strcpy(p, s[i]);
            // 更新指针位置，跳过已写入的字符
            p += strlen(s[i]);
        }
        if (num == 0) {
            break;
        }
    }

    return s1;
}

int main() {
    int num = 1987;
    char* roman = intToRoman(num);
    if (roman != NULL) {
        printf("Roman numeral: %s\n", roman);
        free(roman);
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
