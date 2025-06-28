//P5724 【深基4.习5】求极差 / 最大跨度值
#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	//sort快速排序函数
	sort(arr,arr+n);
	cout<<arr[n-1]-arr[0]<<endl;
	
	system("pause");
	
	return 0;
}
