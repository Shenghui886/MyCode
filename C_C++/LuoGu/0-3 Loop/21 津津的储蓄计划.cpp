//P1089 [NOIP2004 提高组] 津津的储蓄计划
#include<iostream>
using namespace std;

int main() {
	
	int arr[12];for(int i=0;i<12;i++)cin>>arr[i];
	int sum=0,mama=0;
	for(int i=0;i<12;i++)
	{
		sum+=300;
		if(sum-arr[i]<0)
		{
			cout<<'-'<<i+1<<endl;
			return 0;
		}
		else
		{
			sum-=arr[i];
			mama+=sum/100*100;
			sum%=100;
		}
	}
	cout<<sum+mama*1.2<<endl;
	
	return 0;
}
