// P1152 欢乐的跳

#include<stdio.h>
#include<stdbool.h>

int main(void) {
	
	static bool arr[1000];
	
	int a, b, count = 0;
	scanf("%d", &a);
	while(scanf("%d", &b) != EOF)
	{
		int abs = (a - b) < 0 ? (b - a) : (a - b);
		count++;
		arr[abs >= 1000 ? 0 : abs] = true;
		a = b;
	}
	
	for(int i = 1; i < count; i++)
		if(!arr[i])
		{
			puts("Not jolly");
			return 0;
		}
	puts("Jolly");
	
	return 0;
}
