
#include <stdio.h>

// 数组指针--是指针-存放数组的地址
int main()
{
	int* p = NULL;    // p是整形指针-指向整形的指针-可以存放整形的指针
	char* pc = NULL;  // pc是字符指针-指向字符的指针-可以存放字符的地址
	int arr[10] = { 0 };
	// arr-首元素地址
	// &arr[0]-首元素的地址
	// &arr -数组的地址
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p1[10];         // 这是一个存放指针的数组
	int(*p)[10] = &arr;  // 将数组的地址存起来
	// 上面的p就是数组指针，是存放数组的指针，*p是一个指针，存放一个数组，
	// 数组有十个元素，都是int形的
	return 0;
}

int main()
{
	char* arr[5];
	char*(*pa)[5] = &arr;
	// pa为指针变量的名字；*说明pa是指针;[5]说明pa指向的数组是5个元素的
	// char*说明pa指向数组的元素类型时char*
	int arr2[10] = { 0 };
	int(*pa2)[10] = &arr2;
	return 0;
}

 用数组指针打印每个元素
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = &arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	//int(*pa)[10] = &arr;
	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", *(*pa + i));   // *pa是arr的地址，*pa+i可以遍历后面元素的地址
	//}
	/*for (i = 0; i < 10; i++)
	{
		printf("%d ", (*pa)[i]);
	}*/
	return 0;
}

void print1(int arr[3][5], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void print2(int(*p)[5], int x, int y)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			printf("%d ", p[i][j]);
			printf("%d ", *(p[i] + j));
			printf("%d ", *(*(p + i)+j));
			printf("%d ", (*(p + i))[j]);   // *(p+i）=p[i]=arr[i]
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print1(arr, 3, 5);   
	print2(arr, 3, 5);
	// 这里的arr是首元素地址；
	// 而此二维数组一共三行，就看做3个元素,每个元素又是一个一维数组，有5个元素
	return 0;
}

//解释
// int arr[5]；       arr是一个5个元素的整形数组
// int *parr1[10];    parr1是一个数组，数组有10个元素，每个元素的类型是int*; parr1是指针数组
// int (*parr2)[10];  parr2是一个指针，指向了一个数组，数组有10个元素，每个元素类型为int ，parr2是数组指针
// int (*parr3[10])[5];parr3是一个数组，所以剩下的int(*)[5]是元素类型，该数组有10个元素，每个元素是一个指针，
// 该数组指针指向的元素有5个元素,每个元素是int