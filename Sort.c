#include<stdio.h>
#include<stdlib.h>

void BulleSort() {
   int a[8] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	int i, j;//用于循环
	int temp;//中间变量用于交换数组中的数值
	for (i = 0; i < 7; i++)//外层循环要循环数字数值长度减1次
	{	
		/*内层循环的次数将越来越少，因为冒牌排序第一趟就可以将数
		组中最大的一个数放到最后，第二趟就可以将次大的数放在后面
		，所以随着外层循环次数的增多，内层循环将会变少。*/
		for (j = 0; j < 7 - i; j++)
		{
			if (a[j]>a[j+1])//逆序则借助中间变量交换数值
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	printf("冒泡排序的结果为：\n");
	for (i = 0; i < 8; i++)//将数组输出
	{
		printf("%3d",a[i]);
	}
	printf("\n");
}

int a[101],n;
//定义全局变量，这两个变量需要在子函数中使用
void quicksort(int left, int right) {
	int i, j, t, temp;
	if(left > right)
		return;
    temp = a[left]; //temp中存的就是基准数
    i = left;
    j = right;
    while(i != j) { //顺序很重要，要先从右边开始找
    	while(a[j] >= temp && i < j)
    		j--;
    	while(a[i] <= temp && i < j)//再找右边的
    		i++;       
    	if(i < j)//交换两个数在数组中的位置
    	{
    		t = a[i];
    		a[i] = a[j];
    		a[j] = t;
    	}
    }
    //最终将基准数归位
    a[left] = a[i];
    a[i] = temp;
    quicksort(left, i-1);//继续处理左边的，这里是一个递归的过程
    quicksort(i+1, right);//继续处理右边的 ，这里是一个递归的过程
}

int main() ｛
        BulleSort();
	system("pause");
	return 0;
}
