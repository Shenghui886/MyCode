//P1427 小鱼的数字游戏

#include<iostream>
using namespace std;

int main() {
	
	int arr[100],i;
	for(i=0;i<100;i++)
	{
		cin>>arr[i];
		if(arr[i]==0)
			break;
	}
	for(;i>0;i--)
		cout<<arr[i-1]<<" ";
	cout<<endl;
	
	return 0;
}
