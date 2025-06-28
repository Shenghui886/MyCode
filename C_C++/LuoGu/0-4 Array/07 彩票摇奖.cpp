//P2550 [AHOI2001] 彩票摇奖

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n;cin>>n;
	int arr[n+1][7];
	for(int i=0;i<n+1;i++)
		for(int j=0;j<7;j++)
			cin>>arr[i][j];
	int bone[7];for(int i=0;i<7;i++)bone[i]=0;
	for(int i=1;i<=n;i++)
	{
		int count=7;
		for(int j=0;j<7;j++)
			for(int l=0;l<7;l++)
				if(arr[i][j]==arr[0][l])
					count--;
		if(count!=7)
			bone[count]++;
	}
	
	for(int i=0;i<7;i++)
		cout<<bone[i]<<' ';
	cout<<endl;
	
	return 0;
}
