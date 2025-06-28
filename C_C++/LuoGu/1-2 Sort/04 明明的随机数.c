//P1059 [NOIP2006 普及组] 明明的随机数

#include<stdio.h>
#include<stdbool.h>

int main(void) {
	
	bool arr[1000] = {false};
	int n, temp, count = 0;
	scanf("%d", &n);
	for(int i = 0; i < n ; i++)
	{
		scanf("%d", &temp);
		if(!arr[temp])
		{
			count++;
			arr[temp] = true;
		}
	}
	printf("%d\n", count);
	for(int i = 0; i < 1000; i++)
		if(arr[i])
			printf("%d ", i);
	putchar('\n');
	
	return 0;
}
