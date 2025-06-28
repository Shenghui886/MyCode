// P1116 车厢重组

#include<stdio.h>

int main(void) {
	
	int n, arr[10000], count = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", arr + i);
	
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n - i - 1; j++)
			if(arr[j] > arr[j + 1])
			{
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
				count++;
			}
	printf("%d", count);
	
	return 0;
}
