//P2141 [NOIP2014 普及组] 珠心算测验

#include<bits/stdc++.h> 
using namespace std;

int main() {
	
	int n;cin>>n;
	int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	int count=0;
	for(int i=n;i>1;i--)
	{
		for(int j=i-1;j>0;j--)
		{
			int l;
			for(l=j-1;l>=0;l--)
			{
				if(arr[i]==arr[j]+arr[l])
				{
					count++;
					break;
				}
			}
			if(l!=-1)
				break;
		}
	}
	
	cout<<count<<endl;
	
	return 0;
}
