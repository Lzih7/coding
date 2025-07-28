/*优先级处理：加括号*/  
/*解引用高优先级*/
/*防止times跑飞，限制变量范围*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* convert(char* s, int numRows) {
    char s1[100][20];  //二维数组初始化必须[]内两个常量，数或宏
    for(int i=0;i<100;i++){
        for(int j=0;j<20;j++){
            s1[i][j]=0;
        }
    }
    int times=0;
    for(int i=0,j=0;*(s+times)!='\0'&&j<20;){
        if(i==0){
            while(i<numRows&&times<strlen(s)){
                s1[i++][j]=*(s+times);
                times++;
            }
            i-=1;
        }
        if(i==numRows-1){
            while(i>1&&times<strlen(s)){
                s1[--i][++j]=*(s+times);
                times++;
            }
            --i;
            ++j;
        }
    }  
    char* s2=(char*)malloc(sizeof(char)*(strlen(s)+1));
    for(int i=0;i<strlen(s)+1;i++){
        s2[i]=0;
    }
    int k=0;
    for(int i=0;i<numRows;i++){
        for(int j=0;j<20;j++){
            if(s1[i][j]!=0){
                s2[k]=s1[i][j];
                k++;
            }
        }
    }
    s2[k]='\0';
    return s2;
}

int main(){
    char s[30];
    fgets(s,30-1,stdin);
    char *s0=convert(s,3);
    for(int i=0;i<strlen(s0);i++){  //必须是i<strlen(s0)，i<30会有脏数据
        printf("%c",s0[i]);
    }
    free(s0);
    return 0;
}