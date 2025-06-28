// P1591 阶乘数码
//高精乘

#include<iostream>
using namespace std;

void mul(int n, short arr[])
{
	for(int i = 0; i < 3000; i++)
		arr[i] *= n;
	for(int i = 0; i < 3000; i++)
	{
		arr[i + 1] += arr[i] / 10;
		arr[i] %= 10; 
	}
}

int main() {
	
	int num; cin >> num;
	int n, m, count;
	for(int l = 0; l < num; l++)
	{
		short arr[3000] = {1};
		count = 0;
		cin >> n >> m;
		for(int i = 2; i <= n; i++)
			mul(i, arr);
		for(int i = 2999; i >= 0; i--)
			if(arr[i])
			{
				for(int j = i; j >= 0; j--)
					if(arr[j] == m)
						count++;
				break;
			}
		cout << count << endl;
	}
	
	return 0;
}
