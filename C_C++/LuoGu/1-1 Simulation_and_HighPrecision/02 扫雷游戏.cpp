//P2670 [NOIP2015 普及组] 扫雷游戏

#include<iostream>
#include<string.h>
using namespace std;

char arr[102][102];

int main() {
	
	memset(arr , '?' , sizeof arr);
	int m,n;cin >> m >> n;
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
		{
			cin >> arr[i][j];
		}
	
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(arr[i][j] == '?')
			{
				int n=0;
				for(int x = i - 1;x <= i + 1;x++)
					for(int y = j - 1;y <= j + 1;y++)
						if(arr[x][y] == '*')
							n++;
				arr[i][j] = n + '0';
			}
		}
	}
	
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
