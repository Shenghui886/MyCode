//P1319 压缩技术

#include<iostream>
using namespace std;

int arr[1000];

int main() {
	
	int n;cin>>n;
	int sum=0,cnt=0;for(int i=0;sum!=n*n;i++)cin>>arr[i],sum+=arr[i],cnt++;
	for(int i=0,count=0;i<cnt;i++)
	{
		if(i&1)
			for(int j=0;j<arr[i];j++)
			{
				cout<<1,count++;
				if(count%n==0)
					cout<<endl;
			}
		else
			for(int j=0;j<arr[i];j++)
			{
				cout<<0,count++;
				if(count%n==0)
					cout<<endl;
			}
	}
	
	return 0;
}
