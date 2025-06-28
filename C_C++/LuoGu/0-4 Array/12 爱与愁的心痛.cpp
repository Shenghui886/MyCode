//P1614 爱与愁的心痛

#include<iostream>
using namespace std;

int num[3000];

int main() {
	
	int n,m;cin>>n>>m;
	int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
	
	for(int i=0;i<=n-m;i++)
		for(int j=i;j<i+m;j++)
			num[i]+=arr[j];
	for(int i=0;i<n-m;i++)
		if(num[i]<num[i+1])
		{
			num[i]+=num[i+1];
			num[i+1]=num[i]-num[i+1];
			num[i]-=num[i+1];
		}
	cout<<num[n-m]<<endl;
	
	return 0;
}
