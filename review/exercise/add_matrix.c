#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define MAXSIZE 100 // 假设非零元个数的最大值为100
typedef struct
{
    int i, j;   // 非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
    ElemType e; // 非零元的值
} Triple;

typedef struct
{
    Triple data[MAXSIZE]; // 非零元三元组表
    int m, n, len;        // 矩阵的行数、列数和非零元个数
} TSMatrix;

/*
三元组是有序的
*/

bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ)
{
    if (pM->m != pN->m || pM->n != pN->n)
        return false;
    pQ->m = pM->m;
    pQ->n = pM->n;

    int Qdatapos = 0;
    int m = 0;
    int n = 0;
    int flag = -1;
    // 使用归并的思想实现相加
    while (1)
    {
        if (m == pM->len && n == pN->len)
            break;
        if (m == pM->len)
            flag = 1;
        else if (n == pN->len)
            flag = 2;
        else
        {
            if (pM->data[m].i > pN->data[n].i)
                flag = 1;
            else if (pM->data[m].i == pN->data[n].i)
            {
                if (pM->data[m].j > pN->data[n].j)
                    flag = 1;
                else if (pM->data[m].j == pN->data[n].j)
                    flag = 0;
                else
                    flag = 2;
            }
            else
                flag = 2;
        }
        switch (flag)
        {
        case 1:
            pQ->data[Qdatapos].i = pN->data[n].i;
            pQ->data[Qdatapos].j = pN->data[n].j;
            pQ->data[Qdatapos].e = pN->data[n].e;
            Qdatapos++;
            n++;
            break;
        case 2:
            pQ->data[Qdatapos].i = pM->data[m].i;
            pQ->data[Qdatapos].j = pM->data[m].j;
            pQ->data[Qdatapos].e = pM->data[m].e;
            Qdatapos++;
            m++;
            break;
        case 0:
            pQ->data[Qdatapos].i = pM->data[m].i;
            pQ->data[Qdatapos].j = pM->data[m].j;
            pQ->data[Qdatapos].e = pM->data[m].e + pN->data[n].e;
            Qdatapos++;
            m++;
            n++;
            break;
        default:
            return false;
        }
    }
    pQ->len = Qdatapos;
    for (int i = 0; i < pQ->len; i++)
    {
        if (pQ->data[i].e == 0)
        {
            for (int j = i; j < pQ->len; j++)
            {
                pQ->data[j] = pQ->data[j + 1];
            }
            pQ->len--;
            i--;
        }
    }
    return true;
}