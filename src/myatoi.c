/*一遍过！*/
int myAtoi(char* s) {
    int num = 0;
    int num1 = 0;
    char s1[201];
    int flag = 1;
    if (s[0] == ' ') {
        for (num = 0; s[num] == ' '; num++)
            ;
    }
    if (s[num] == '+')
        num++;
    else if (s[num] == '-') {
        num++;
        flag = -1;
    }
    while (s[num] >= '0' && s[num] <= '9') {
        s1[num1++] = s[num++];
    }
    s1[num1] = '\0';
    long long res = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        res = res * 10 + (s1[i] - '0');
        if (flag == 1 && res > INT_MAX) {
            return INT_MAX;
        }
        if (flag == -1 && -res < INT_MIN) {
            return INT_MIN;
        }
    }

    return res * (flag);
}