#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//时间：O(N ^ 2)
//空间：O(1)
//稳定性：稳定
//适合场景：接近有序的序列，时间复杂度趋近于O(N),
//		   对于有序的序列，时间复杂度O(N^2)
void InsertSort(int* a, int n) {
	assert(a);
	int i;
	for (i = 0; i < n; i++) {
		//单个元素排序
		//找到已经排好序的最后一个元素的位置
		int end = i;
		//把end + 1 位置的元素插入到合适的位置
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp) {
			a[end + 1] = a[end];
			end--;
		}
		//找到合适的位置
		a[end + 1] = tmp;
	}
}

//时间：O(N^1.3 - 2)
//空间：O(
void ShellSort(int* a, int n) {
	int gap = n;
	int i;
	//int num;
	//for (; gap >= 1; gap -= num) //预排序的次数
	//for (num = 0; num < gap; ++num) //待排序的组别
	while (gap > 1) {
		//gap > 1 --> 预排序过程，让数组接近有序
		//gap = 1 --> 排序过程
		gap = gap / 3 + 1; //保证最后一次gap为1的插入排序
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

//时间：O(N^2)
//空间：O(1)
//稳定性：可以变成稳定的
void SelectSort(int* a, int n) {
	int begin = 0, end = n - 1;
	while (begin < end) {
		//每次选一个最大的和最小的，放到相应的位置
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
		//判断元素的位置是否发生变化
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
	testShellSort();
	testSelectSort();

	system("pause");
	return 0;
}
