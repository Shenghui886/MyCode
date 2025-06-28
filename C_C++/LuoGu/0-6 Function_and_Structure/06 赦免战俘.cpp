//P5461 赦免战俘

#include<iostream>
using namespace std;

bool arr[1200][1200];

void She(int m,int n,int p,int q)
{
	for(int i=m;i<n-(n-m)/2;i++)
		for(int j=p;j<q-(q-p)/2;j++)
			arr[i][j]=1;
	if((n-m)==2)
		return;
	She(m,n-(n-m)/2,q-(q-p)/2,q);
	She(n-(n-m)/2,n,p,q-(q-p)/2);
	She(n-(n-m)/2,n,q-(q-p)/2,q);
}

int main() {
	
	int n;cin>>n;
	int m=(2<<(n-1));
	She(0,m,0,m);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
			cout<<(!arr[i][j])<<' ';
		cout<<endl;
	}
	
	return 0;
}
//两种方法均可，速度和空间占用差不多，但下面这个更巧妙。
//bool arr[1100][1100];
//
//int main() {
//	
//	int n;cin>>n;
//	int m=(2<<(n-1));
//	for(int i=1;i<=m;i++)
//		arr[i][1]=1;
//	for(int i=2;i<=m;i++)
//		for(int j=2;j<=i;j++)
//			arr[i][j]=arr[i-1][j-1]^arr[i-1][j];
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=m;j>=1;j--)
//			cout<<arr[i][j]<<' ';
//		cout<<endl;
//	}
//	
//	return 0;
//}

