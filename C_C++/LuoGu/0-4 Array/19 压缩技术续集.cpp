//P1320 压缩技术（续集版）
//不知道测试数据的情况下的版本

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	string arr[200];
	cin>>arr[0];
	int n=arr[0].length();
	for(int i=1;i<n;i++)
		cin>>arr[i];
	int count=0;cout<<n<<' ';
	char v=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]-'0'==v)
				count++;
			else
			{
				v=!v;
				cout<<count<<' ';
				count=1;
			}
		}
	cout<<count<<' '<<endl;
	
	return 0;
}
