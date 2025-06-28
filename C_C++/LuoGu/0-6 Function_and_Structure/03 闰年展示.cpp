//P5737 【深基7.例3】闰年展示

#include<iostream>
using namespace std;

int main() {
	
	int n,m;cin>>n>>m;
	int count=0,arr[1000];
	for(int i=n;i<=m;i++)
		if((!(i%4) && i%100) || !(i%400))
			arr[count++]=i;
	cout<<count<<endl;
	for(int i=0;i<count;i++)
		cout<<arr[i]<<' ';
	
	return 0;
}
