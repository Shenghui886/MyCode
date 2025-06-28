#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	
	int n, max = 0;
	scanf("%d", &n);
	
	char str[200];
	char temp[200];
	
	scanf("%s", str);
	for(int i = 0; i < n - 1; i++)
	{
		scanf("%s", temp);
		if(strlen(temp) > strlen(str) || (strlen(temp) == strlen(str) && strcmp(temp, str) > 0))
		{
			strcpy(str, temp);
			max = i + 2;
		}
	}
	
	printf("%d\n", max);
	puts(str);
	
	return 0;
}
