//P5732 【深基5.习7】杨辉三角

#include<iostream>
using namespace std;

int arr[20][20];

int main() {
	
	int n;cin>>n;
	for(int i=0;i<n;i++)
		arr[i][0]=1,arr[i][i]=1;
	for(int i=2;i<n;i++)
		for(int j=1;j<i;j++)
			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
			cout<<arr[i][j]<<' ';
		cout<<endl;
	}
		
	
	return 0;
}
