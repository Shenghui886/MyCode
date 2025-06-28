//P5738 【深基7.例4】歌唱比赛

#include<iostream>
#include<iomanip>
using namespace std;

void sort(int arr[],int m)
{
	for(int i=0;i<m-1;i++)
		if(arr[i]>arr[i+1])
		{
			arr[i]^=arr[i+1];
			arr[i+1]^=arr[i];
			arr[i]^=arr[i+1];
		}
	for(int i=m-2;i>0;i--)
		if(arr[i]<arr[i-1])
		{
			arr[i]^=arr[i-1];
			arr[i-1]^=arr[i];
			arr[i]^=arr[i-1];
		}
}

int main() {
	
	int m,n;cin>>n>>m;
	int arr[m];
	float sum=0;
	for(int i=0;i<n;i++)
	{
		for(int i=0;i<m;i++)
			cin>>arr[i];
		int temp=0;
		sort(arr,m);
		for(int j=1;j<m-1;j++)
			temp+=arr[j];
		if(temp>sum)
			sum=temp;
	}
	cout<<fixed<<setprecision(2)<<sum/(m-2)<<endl;
	
	return 0;
}
