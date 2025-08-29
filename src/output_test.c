#include<stdio.h>

int main(){
    char str[50];
    // scanf("%s", str);
    fgets(str, sizeof(str), stdin); // 使用fgets读取一行输入
    printf("%s",str);

    return 0;
}