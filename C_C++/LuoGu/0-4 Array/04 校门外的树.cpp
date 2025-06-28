//P1047 [NOIP2005 普及组] 校门外的树

#include<iostream>
using namespace std;

int main() {
	
	int lenth,n;cin>>lenth>>n;
	int arr[n*2];for(int i=0;i<n*2;i++)cin>>arr[i];
	int tree[lenth+1];for(int i=0;i<lenth+1;i++)tree[i]=1;
	for(int i=0;i<n*2;i+=2)
		for(int j=arr[i];j<=arr[i+1];j++)
			tree[j]=0;
	int count=0;
	for(int i=0;i<lenth+1;i++)
		if(tree[i])
			count++;
	cout<<count<<endl;
	
	return 0;
}
