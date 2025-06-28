//P1067 [NOIP2009 普及组] 多项式输出

#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	
	int n;cin >> n;
	int temp;
	if(n == 0)
	{
		cin >> temp;
		cout << temp << endl;
		return 0;
	}
	bool count = 0;
	for(int i = n; i > 1; i--)
	{
		cin >> temp;
		if(temp)
		{
			if(count)
			{
				if(temp != 1 && temp != -1)
					printf("%+dx^%d", temp, i);
				else if(temp == 1)
					printf("+x^%d", i);
				else
					printf("-x^%d", i);
			}
			else
			{
				if(temp != 1 && temp != -1)
					printf("%dx^%d", temp, i);
				else if(temp == 1)
					printf("x^%d", i);
				else
					printf("-x^%d", i);
				count = 1;
			}
		}
	}
	if(count)
	{
		cin >> temp;
		if(temp)
		{
			if(temp != 1 && temp != -1)
				printf("%+dx", temp);
			else if(temp == 1)
				printf("+x");
			else
				printf("-x");
		}
	}
	else
	{
		cin >> temp;
		if(temp)
		{
			if(temp != 1 && temp != -1)
				printf("%dx", temp);
			else if(temp == 1)
				printf("x");
			else
				printf("-x");
			count = 1;
		}
	}
	if(count)
	{
		cin >> temp;
		if(temp)
			printf("%+d", temp);
	}
	else
	{
		cin >> temp;
		if(temp)
			printf("%d", temp);
	}
	
	return 0;
}
