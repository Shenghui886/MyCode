//P1068 [NOIP2009 普及组] 分数线划定

#include<stdio.h>

struct vol
{
	int id;
	int score;
};

struct vol a[10000], b[10000];

void qsort(struct vol *arr, int L, int R)
{
	if(L >= R)
		return;
	struct vol pivot = arr[L + (R - L) / 2];
	int cnta = 0, cntb = 0;
	
	for(int i = 0; i <= R; i++)
	{
		if(arr[i].score > pivot.score)
			a[cnta++] = arr[i];
		else if(arr[i].score == pivot.score)
		{
			if(arr[i].id < pivot.id)
				a[cnta++] = arr[i];
			else if(arr[i].id > pivot.id)
				b[cntb++] = arr[i];
		}
		else
			b[cntb++] = arr[i];
	}
	int i = 0;
	for(;i < cnta; i++)
		arr[i] = a[i];
	arr[i++] = pivot;
	for(;i < cnta + cntb + 1; i++)
		arr[i] = b[i - (cnta + 1)];
	
	qsort(arr, L, cnta - 1);
	qsort(arr, R - cntb + 1, R);
	
}

int main(void) {
	
	struct vol arr[10000];
	int n, m;
	scanf("%d %d", &n, &m);
	
	m *= 1.5;
	
	for(int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].id, &arr[i].score);
	
	qsort(arr, 0, n - 1);
	
	int num = m;
	for(;; num++)
		if(arr[num].score != arr[m - 1].score)
			break;
	
	
	printf("%d %d\n", arr[m - 1].score, num);
	
	for(int i = 0; i < m; i++)
		printf("%d %d\n", arr[i].id, arr[i].score);
	
	for(int i = m;; i++)
	{
		if(arr[i].score != arr[m - 1].score)
			break;
		printf("%d %d\n", arr[i].id, arr[i].score);
	}
	
	
	return 0;
}
