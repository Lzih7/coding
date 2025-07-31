#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
struct _seqlist
{
	ElemType elem[MAXSIZE];
	int last;
};
typedef struct _seqlist SeqList;

void del_x2y(SeqList *L, ElemType x, ElemType y)
{
	int j = 0;
	if (L->last == 0)
		return;
	for (int i = 0; i <= L->last; i++)
	{
		if (!(L->elem[i] >= x && L->elem[i] <= y))
		{
			L->elem[j] = L->elem[i];
			j++;
		}
	}
	L->last = (--j);
	return;
}
// double pointer method
// 都从0开始遇到不成立的位置i j才相异