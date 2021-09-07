#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//����ṹ��
typedef struct {
	int r[6];
	int length = 6;
}Sqlist;

//}
//��������
void swap(Sqlist* L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void Insertsort(Sqlist* L, int length) {  //�򵥲�������        
	int i, j;
	 L->r[0] = 0;  //�ڱ�
	 for (i = 2; i < length; i++)
	 {
		 if (L->r[i] < L->r[i - 1])
		 {
			 L->r[0] = L->r[i];
			 for (j = i - 1; j > 0; j--)
			 {
				 if (L->r[j] > L->r[0])
					 L->r[j + 1] = L->r[j];
				 else
				 {
					 break;
				 }
			 }
			 L->r[j + 1] = L->r[0];
		 }
	 }
}

int main() {
	int i = 0;
	Sqlist B0;
	Sqlist* L = &B0;
	for (i = 1; i < L->length; i++)
		cin >> L->r[i];
	Insertsort(L, L->length);
	for (i = 1; i < L->length; i++)
		cout << L->r[i]<<" ";
	return 0;
}