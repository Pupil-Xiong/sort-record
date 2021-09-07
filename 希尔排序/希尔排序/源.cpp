#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//����ṹ��
typedef struct {
	int r[7];
	int length = 7;
}Sqlist;

//��������
void swap(Sqlist* L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void shellsort(Sqlist* L, int length)   //ϣ������      
{
	int i = 0, j = 0, gap = 0;   //r[0]�ڱ���r[1]�̶�
	for (gap = 3; gap > 0; gap /= 2)
	{
		for (i = gap + 1; i < length; i++)  //�ӵڶ�λ��ʼ���̶���һ�����ۻ������Դ���gap
		{
			if (L->r[i] < L->r[i - gap])    //�����������ǰ��С����ô�����滻
			{
				L->r[0] = L->r[i];
				for (j = i; (j - gap) > 0 && L->r[0] < L->r[j - gap]; j -= gap)//ѭ���Ƚϣ�
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