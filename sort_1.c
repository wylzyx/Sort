#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//ʱ�䣺O(N ^ 2)
//�ռ䣺O(1)
//�ȶ��ԣ��ȶ�
//�ʺϳ������ӽ���������У�ʱ�临�Ӷ�������O(N),
//		   ������������У�ʱ�临�Ӷ�O(N^2)
void InsertSort(int* a, int n) {
	assert(a);
	int i;
	for (i = 0; i < n; i++) {
		//����Ԫ������
		//�ҵ��Ѿ��ź�������һ��Ԫ�ص�λ��
		int end = i;
		//��end + 1 λ�õ�Ԫ�ز��뵽���ʵ�λ��
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp) {
			a[end + 1] = a[end];
			end--;
		}
		//�ҵ����ʵ�λ��
		a[end + 1] = tmp;
	}
}

//ʱ�䣺O(N^1.3 - 2)
//�ռ䣺O(
void ShellSort(int* a, int n) {
	int gap = n;
	int i;
	//int num;
	//for (; gap >= 1; gap -= num) //Ԥ����Ĵ���
	//for (num = 0; num < gap; ++num) //����������
	while (gap > 1) {
		//gap > 1 --> Ԥ������̣�������ӽ�����
		//gap = 1 --> �������
		gap = gap / 3 + 1; //��֤���һ��gapΪ1�Ĳ�������
		for (i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp) {
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//ʱ�䣺O(N^2)
//�ռ䣺O(1)
//�ȶ��ԣ����Ա���ȶ���
void SelectSort(int* a, int n) {
	int begin = 0, end = n - 1;
	while (begin < end) {
		//ÿ��ѡһ�����ĺ���С�ģ��ŵ���Ӧ��λ��
		int i, max, min;
		max = min = begin;
		for (i = begin; i < end; i++) {
			if (a[i] < a[min]) {
				min = i;
			}
			if (a[i] >= a[max]) {
				max = i;
			}
		}
		Swap(&a[begin], &a[min]);
		//�ж�Ԫ�ص�λ���Ƿ����仯
		if (max == begin) {
			max = min;
		}
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}

void PrintArry(int* a, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void testInsertSort() {
	int a[10] = { 1, 10, 8, 9, 5, 7, 3, 2, 6, 0 };
	PrintArry(a, sizeof(a) / sizeof(a[0]));
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArry(a, sizeof(a) / sizeof(a[0]));
}

void testShellSort() {
	int a[10] = { 1, 10, 8, 9, 5, 7, 3, 2, 6, 0 };
	PrintArry(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArry(a, sizeof(a) / sizeof(a[0]));
}

void testSelectSort() {
	int a[10] = {1, 10, 8, 9, 5, 7, 3, 2, 6, 0 };
	PrintArry(a, sizeof(a) / sizeof(a[0]));
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintArry(a, sizeof(a) / sizeof(a[0]));
}

int main() {
	testInsertSort();
	//testShellSort();
	//testSelectSort();

	system("pause");
	return 0;
}