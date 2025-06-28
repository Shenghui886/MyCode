//P1012 [NOIP1998 提高组] 拼数

#include<stdio.h>
#include<string.h>

#define read(a){char c; while((c = getchar()) > 47) a = (a << 3) + (a << 1) + (c ^ 48); if(c == '\r')getchar();}

int main(void) {
	
	char arr[20][10];
	short n = 0; 
	read(n);
	for(int i = 0; i < n; i++)
		scanf("%s", arr[i]);
	
	char str1[20];
	char str2[20];
	
	for(int i = 0; i < n - 1; i ++)
		for(int j = 0; j < n - 1 - i; j++)
		{
			strcpy(str1, arr[j]);
			strcat(str1, arr[j + 1]);
			strcpy(str2, arr[j + 1]);
			strcat(str2, arr[j]);
			if(strcmp(str1, str2) < 0)
			{
				char temp[10];
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], temp);
			}
		}
	
	for(int i = 0; i < n; i++)
		printf("%s", arr[i]);
	
	return 0;
}
