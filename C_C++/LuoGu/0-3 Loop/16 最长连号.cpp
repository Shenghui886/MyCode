//P1420 最长连号
#include<iostream>
using namespace std;

int main() {
	
	int n,max=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int count=1;
	for(int i=0;i<n;i++)
	{
		if(i-count+1>max)
			max=i-count+1;
		if(arr[i]+1!=arr[i+1])
			count=i+1;
	}
	cout<<max<<endl;
	
	system("pause");
	
	return 0;
}
