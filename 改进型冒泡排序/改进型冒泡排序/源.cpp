#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//定义结构体
typedef struct {
	int r[10];
	int length = 6;
}Sqlist;

//数组长度
//int length(int r[]) {
	//return sizeof(r) / sizeof(r[0]);
//}
//交换函数
void swap(Sqlist* L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void Bubblelist(Sqlist* L, int length) {  //改进型冒泡排序         
	int i, j;
	bool flag = true;
	for (i = 1; i < L->length && flag; i++) {
		flag = false;
		for (j = L->length - 1; j >= i; j--) {
			if (L->r[j - 1] > L->r[j]) {
				swap(L, (j - 1), j);
				flag = true;      //若本次循环中交换了顺序，那么flag变为true，那么就有继续下一个循环的必要
			}
		}
	}
}

int main() {
	int i = 0;
	Sqlist B0;
	Sqlist* L = &B0;
	for (i = 0; i < L->length; i++)
		cin >> L->r[i];
	Bubblelist(L, L->length);
	for (i = 0; i < L->length; i++)
		cout << L->r[i];
	return 0;
}