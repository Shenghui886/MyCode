//P1923 【深基9.例4】求第 k 小的数

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define read(a) {char c;while((c = getchar()) > 47) a = (a<<3) + (a<<1) + (c^48);}

int qfind(int *arr, int n,int *b, int k)
{
	if(n == 1)
		return arr[0];
	
	int pivot = arr[n / 2];
	int NumArr = 0; int NumB = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] > pivot)
			b[NumB++] = arr[i];
		else if(arr[i] < pivot)
			arr[NumArr++] = arr[i];
	}
	if(NumArr > k)
		return qfind(arr, NumArr, b, k);
	else if(k >= n - NumB)
		return qfind(b, NumB, arr, k + NumB - n);
	else
		return pivot;
}

int main(void) {
	
	int n, k;
	scanf("%d %d", &n, &k);
	int *arr = (int *)malloc(n * sizeof(int));
	int *b = (int *)malloc(n * sizeof(int));
	memset(arr, 0, n * sizeof(int));
	memset(b, 0, n * sizeof(int));
	getchar();
	for(int i = 0; i < n; i++)
		read(arr[i]);
	printf("%d\n", qfind(arr, n, b, k));
	free(arr);
	free(b);
	
	return 0;
}
