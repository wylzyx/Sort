#include<stdio.h>
#include<stdlib.h>

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintArry(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}

//三数取中法
int getMid(int* a, int left, int right) {
	int mid = left + (right - left) / 2;
	if(a[left] < a[right]) {
		if (a[right] < a[mid]) {
			return right;
		}
		else if(a[left] < a[mid]) {
			return mid;
		}
		else {
			return left;
		}
	}
	else {
		if (a[left] < a[mid]) {
			return left;
		}
		else if (a[right] < a[mid]) {
			return mid;
		}
		else {
			return right;
		}
	}
}

int PartSort1(int* a, int left, int right) {
	int key = a[left];
	int start = left;
	//寻找大小元素交换
	//从右边找小于key的值
	while (left < right) {
		while (left < right && a[right] >= key) {
			--right;
		}
		//从左边找大于key的值
		while (left < right && a[left] <= key) {
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	//key的位置确定：left right相遇的位置
	Swap(&a[start], &a[left]);
	return left;
}


//挖坑法
int PartSort2(int* a, int left, int right) {
	int key = a[left];
	while (left < right) {
		//从右边找小
		while (left < right && a[right] >= key) {
			--right;
		}
		a[left] = a[right];
		//从左边找大的
		while (left < right && a[left] <= key) {
			++left;
		}
		a[right] = a[left];
	}
	//存放key
	a[left] = key;
	return left;
}

//前后指针
int PartSort3(int* a, int left, int right) {
	//int mid = getMid(a, left, right);
	//Swap(&a[mid], &a[left]);

	//最后一个小于key的值
	int key = a[left];
	//下一个小于key的值
	int prev = left;
	int cur = left + 1;
	while (cur <= right) {
		//如果下一个小于key的值位置于上一个小于key的位置不连续
		//说明中间有大于key的值，进行交换，大-->向后移动，小<--向前移动
		if (a[cur] < key && ++prev != cur) {
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[left], &a[prev]);
	return prev;
}

//非递归
void QuickSortNOR(int* a, int left, int right) {
	Stack st;
	StackInit(&st);
	if (left < right) {
		Stackpush(&st, right);
		Stackpush(&st, left);
	}
	while (StackEmpty(&st) == 0) {
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		//划分当前区间
		int mid = PartSort3(a, begin, end);
		//划分左右子区间
		if (begin < mid - 1) {
			StackPush(&st, mid - 1);
			StackPush(&st, begin);
		}
		if (mid + 1 < end) {
			StackPush(&st, mid - 1);
			StackPush(&st, begin);
		}
	}
}

void QuickSort(int* a, int left, int right) {
	if (left >= right) {
		return;
	}
	/*else if (right - left + 1 < 5) {
		InsertSort(a, sizeof(a) / sizeof(a[0]));
	}*/
	else {
		//int mid = PartSort1(a, left, right);
		//int mid = PartSort2(a, left, right);
		int mid = PartSort3(a, left, right);
		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
	}
	
}

void testQuickSort() {
	int a[10] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	PrintArry(a, sizeof(a) / sizeof(a[0]));
	QuickSort(a, 0, 9);
	PrintArry(a, sizeof(a) / sizeof(a[0]));
}

int main() {
	testQuickSort();
	system("pause");
	return 0;
}