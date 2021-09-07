#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//定义结构体
typedef struct {
	int r[7];
	int length = 7;
}Sqlist;

//交换函数
void swap(Sqlist* L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void shellsort(Sqlist* L, int length)   //希尔排序      
{
	int i = 0, j = 0, gap = 0;   //r[0]哨兵，r[1]固定
	for (gap = 3; gap > 0; gap /= 2)
	{
		for (i = gap + 1; i < length; i++)  //从第二位开始，固定第一个，累积到可以代替gap
		{
			if (L->r[i] < L->r[i - gap])    //如果满足后面比前面小，那么就做替换
			{
				L->r[0] = L->r[i];
				for (j = i; (j - gap) > 0 && L->r[0] < L->r[j - gap]; j -= gap)//循环比较，
				{
					L->r[j] = L->r[j - gap];
				}
				L->r[j] = L->r[0];
			}
		}
	}
}




int main() {
	int i = 0;
	Sqlist B0;
	Sqlist* L = &B0;
	for (i = 1; i < L->length; i++)
		cin >> L->r[i];
	shellsort (L, L->length);
	for (i = 1; i < L->length; i++)
		cout << L->r[i];
	return 0;
}