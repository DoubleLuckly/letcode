#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ATTRAY_SIZE(a) sizeof(a)/sizeof(type(a[0]))

void swap(int *arr, int i, int j)
{
	if (i == j || arr == NULL)
		return;
//	int temp;
//	temp = *(arr + i);
//	*(arr + i) = *(arr + j);
//	*(arr + j) = temp;

	/* a and b not in same memory */
	*(arr + i) = *(arr + i) ^ *(arr + j);
	*(arr + j) = *(arr + i) ^ *(arr + j);
	*(arr + i) = *(arr + i) ^ *(arr + j);
}

void select_sort(int *arr, int length)
{
	if (length <= 2 || arr == NULL)
		return;

	int i = 0, j = 0;
	for (i = 0; i < length - 1; i++)  //i ~ N-2
	{
		int min_index = i;
		for (j = i + 1; j < length; j++) //i+1 ~ N-1
		{
			min_index = *(arr + i) > *(arr + j) ? j : min_index;//find the min value's index
		}
		swap(arr, i, min_index);
	}

}

void bubble_sort(int *arr, int length)
{
	if (length <= 2 || arr == NULL)
		return;

	int i = 0, j = 0;
	for (i = length - 1; i > 0; i--) //0 ~ N-1
	{
		for (j = 0; j < i ; j++) //0 ~ i
		{
			if (*(arr + j) > *(arr + j + 1))
				swap(arr, j, j + 1);
		}
		
	}
}


void print_odd_times_num1(int *arr, int length)
{
	int i = 0, eor = 0;
	if (length < 0 || arr == NULL)
		return;
	for (i = 0; i < length; i++)
		eor ^= *(arr + i);

	printf("%d\n", eor);
}


void print_odd_times_num2(int *arr, int length)
{
	int i = 0, eor = 0;
	if (length < 0 || arr == NULL)
		return;

	for (i = 0; i < length; i++)
		eor ^= *(arr + i);
	
	// eor = a ^ b
	// eor != 0
	// eor right bit 1
	int right_one = eor & (~eor + 1);

	int only_one = 0; //eor'
	for (i = 0; i < length; i++)
	{
		if ((*(arr + i) & right_one) == 0)
			only_one ^= *(arr + i);
	}

	printf("%d %d\n", only_one, eor^only_one);
}

void merge_sort(int *arr, int length)
{
	if (arr == NULL || length < 2)
		return;
	
	process(arr, 0, length - 1);
	return;
}

void process(int *arr, int L, int R)
{
	if (L == R) //arr just have one parameter
		return;
	
	int mid = L + ((R - L) >> 1);
	process(arr, L, mid);
	process(arr, mid + 1, R);

	merge(arr, L, mid, R);
	return;
}

void merge(int *arr, int L, int M, int R)
{
	int *help = (int *)calloc(1, R - L + 1);
	if (help == NULL || arr == NULL)
		return;
	
	int i = 0, p1 = L, p2 = M + 1;
	while(p1 <= M && p2 <= R) {
		help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
	}

	while (p1 <= M) {
		help[i++] = arr[p1++];
	}

	while (p2 <= R) {
		help[i++] = arr[p2++];
	}

	for (i = 0; i < (R - L + 1); i++) {
		arr[L + i] = help[i];
	}

	//printf("merge i %d p1 %d p2 %d\n", i, p1, p2);
//	memcpy(arr + L, help, R - L); //stack operate not use memcpy
	//free(help);//can not free because in stack	
	return;
}

void print_arr(int *arr, int length)
{
	int i = 0;
	if (arr == NULL)
		return;
		
	for (i = 0; i < length; i++)
		printf("%d\n", *(arr + i));

}

int main(int *argc[], int argv)
{
	int ret = 0;

	int test[8] = {10, 6, 7, 4, 5, 8, 9 ,1};
	int test_odd_one[] = {10, 9, 8, 6, 6, 8, 9 ,10, 5};
	int test_odd_two[] = {10, 9, 8, 6, 8, 9 ,10, 5};

	//select_sort(test, ATTRAY_SIZE(test));
	//bubble_sort(test, ATTRAY_SIZE(test));

	//print_arr(test, ATTRAY_SIZE(test));
	//print_odd_times_num1(test_odd_one, ATTRAY_SIZE(test_odd_one));
	//print_odd_times_num2(test_odd_two, ATTRAY_SIZE(test_odd_two));

	printf("before %p\n", test);
	merge_sort(test, 8);
	//printf("after %p\n", test);
	print_arr(test, 8);

	return ret;

}

