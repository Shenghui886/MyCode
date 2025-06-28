#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int arr[10],tall,count=0;
	for(int i=0;i<10;i++)
	{
		cin>>arr[i];
	}
	cin>>tall;
	for(int i=0;i<10;i++)
	{
		if(arr[i]<=tall+30)
		{
			count++;
		}
	}
	cout<<count<<endl;
	
	system("pause");
	
	return 0;
}
