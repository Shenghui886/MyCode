//P5728 【深基5.例5】旗鼓相当的对手

#include<iostream>
#include<math.h>
using namespace std;

int main() {
	
	int n;cin>>n;
	int arr[n][4];
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			cin>>arr[i][j];
	for(int i=0;i<n;i++)
		arr[i][3]=arr[i][0]+arr[i][1]+arr[i][2];
	int count=0;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(abs(arr[i][0]-arr[j][0])<=5 && abs(arr[i][1]-arr[j][1])<=5 && abs(arr[i][2]-arr[j][2])<=5 && abs(arr[i][3]-arr[j][3])<=10)
				count++;
	cout<<count<<endl;
	
	return 0;
}
