// P2676 [USACO07DEC] Bookshelf B

#include<stdio.h>

int a[20000], b[20000], c[20000];

void qsort(int *arr, const int L, const int R)
{
	if(L >= R)
		return;
	
	int pivot = L + (R - L) / 2;
	int cnta = 0, cntb = 0, cntc = 0;
	
	for(int i = L; i <= R; i++)
	{
		if(arr[i] < arr[pivot])
			a[cnta++] = arr[i];
		else if (arr[i] == arr[pivot])
			b[cntb++] = arr[i];
		else
			c[cntc++] = arr[i];
	}
	
	for(int i = 0; i < cnta; i++)
		arr[i + L] = a[i];
	for(int i = 0; i < cntb; i++)
		arr[cnta + i + L] = b[i];
	for(int i = 0; i < cntc; i++)
		arr[cnta + cntb + i + L] = c[i];
	
	qsort(arr, L, L + cnta - 1);
	qsort(arr, R - cntc + 1, R);
	
	return;
}

int main(void) {
	
	static int N, B, arr[20000], sum = 0;
	scanf("%d %d", &N, &B);
	
	for(int i = 0; i < N; i++)
		scanf("%d", arr + i);
	
	qsort(arr, 0, N - 1);
	
	for(int i = N - 1; i >= 0; i--)
	{
		if(sum >= B)
		{
			printf("%d", N - i - 1);
			break;
		}
		sum += arr[i];
	}
	
	return 0;
}
