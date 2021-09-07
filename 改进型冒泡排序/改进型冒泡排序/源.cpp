#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//����ṹ��
typedef struct {
	int r[10];
	int length = 6;
}Sqlist;

//���鳤��
//int length(int r[]) {
	//return sizeof(r) / sizeof(r[0]);
//}
//��������
void swap(Sqlist* L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void Bubblelist(Sqlist* L, int length) {  //�Ľ���ð������         
	int i, j;
	bool flag = true;
	for (i = 1; i < L->length && flag; i++) {
		flag = false;
		for (j = L->length - 1; j >= i; j--) {
			if (L->r[j - 1] > L->r[j]) {
				swap(L, (j - 1), j);
				flag = true;      //������ѭ���н�����˳����ôflag��Ϊtrue����ô���м�����һ��ѭ���ı�Ҫ
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