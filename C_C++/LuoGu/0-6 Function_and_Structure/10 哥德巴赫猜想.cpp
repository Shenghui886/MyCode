//P1304 哥德巴赫猜想

#include<iostream>
#include<string.h>
using namespace std;

//埃筛
void ai(bool arr[])
{
	arr[0]=0,arr[1]=0;
	for(int i=2;i<100;i++)
	{
		for(int j=i*i;j<10000;j+=i)
			arr[j]=0;
	}
}

int main() {
	
	bool arr[10000];
	memset(arr ,true ,sizeof(arr) );
	ai(arr);
	int n;cin >> n;
	for(int i = 4;i <= n;i += 2)
		for(int j = 2;j * 2 <= i;j++)
			if(arr[j] && arr[i-j])
			{
				cout << i << '=' << j << '+' << i-j <<endl;
				break;
			}
	
	return 0;
}
