#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//定义结构体
typedef struct {
	int r[10];
	int length = 6;
}Sqlist;

//}
//交换函数
void swap(Sqlist* L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void Selectsort(Sqlist* L, int length) {  //简单选择排序        
	int i, j;
	int min = 0;
	for (i = 0; i < L->length-1; i++)        //不同位置的序号改变
	{
		min = i;
		for (j = i; j <=L->length-1; j++)    //为 i序号遍历寻找最小值
		{
			if (L->r[j] < L->r[min]) 
			{
				min = j;
			}
		}
		if (min != i)            //如果顺序改变，调用换序函数
			swap(L, min, i);
	}
}

int main() {
	int i = 0;
	Sqlist B0;
	Sqlist* L = &B0;
	for (i = 0; i < L->length; i++)
		cin >> L->r[i];
	Selectsort(L, L->length);
	for (i = 0; i < L->length; i++)
		cout << L->r[i];
	return 0;
}