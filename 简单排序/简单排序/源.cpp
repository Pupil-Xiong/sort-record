#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//����ṹ��
typedef struct {
	int r[10];
	int length = 6;
}Sqlist;

//}
//��������
void swap(Sqlist* L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void Selectsort(Sqlist* L, int length) {  //��ѡ������        
	int i, j;
	int min = 0;
	for (i = 0; i < L->length-1; i++)        //��ͬλ�õ���Ÿı�
	{
		min = i;
		for (j = i; j <=L->length-1; j++)    //Ϊ i��ű���Ѱ����Сֵ
		{
			if (L->r[j] < L->r[min]) 
			{
				min = j;
			}
		}
		if (min != i)            //���˳��ı䣬���û�����
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