//P5730 【深基5.例10】显示屏

#include<iostream>
using namespace std;

int arr[5][400];

int main() {
	
	int n;cin>>n;
	string m;cin>>m;
	int num[n],temp=0;
	while(temp!=n)
	{
		num[temp]=m[temp]-'0';
		temp++;
	}
	for(int i=0;i<n;i++)
	{
		switch (num[i]) {
		case 1:
			for(int j=0;j<5;j++)
				arr[j][i*4]=1;
			for(int j=0;j<5;j++)
				arr[j][i*4+1]=1;
			for(int j=0;j<5;j++)
				arr[j][i*4+3]=1;
			break;
		case 2:
			arr[1][i*4]=1,arr[1][i*4+1]=1,arr[3][i*4+1]=1,arr[3][i*4+2]=1;
			for(int j=0;j<5;j++)
				arr[j][i*4+3]=1;
			break;
		case 3:
			arr[1][i*4]=1,arr[1][i*4+1]=1,arr[3][i*4+1]=1,arr[3][i*4]=1;
			for(int j=0;j<5;j++)
				arr[j][i*4+3]=1;
			break;
		case 4:
			arr[0][i*4+1]=1,arr[1][i*4+1]=1,arr[3][i*4]=1,arr[3][i*4+1]=1,arr[4][i*4]=1,arr[4][i*4+1]=1;
			for(int j=0;j<5;j++)
				arr[j][i*4+3]=1;
			break;
		case 5:
			arr[1][i*4+2]=1,arr[1][i*4+1]=1,arr[3][i*4+1]=1,arr[3][i*4]=1;
			for(int j=0;j<5;j++)
				arr[j][i*4+3]=1;
			break;
		case 6:
			arr[1][i*4+2]=1,arr[1][i*4+1]=1,arr[3][i*4+1]=1;
			for(int j=0;j<5;j++)
				arr[j][i*4+3]=1;
			break;
		case 7:
			arr[1][i*4]=1,arr[1][i*4+1]=1,arr[2][i*4]=1,arr[2][i*4+1]=1,arr[3][i*4]=1,arr[3][i*4+1]=1,arr[4][i*4]=1,arr[4][i*4+1]=1;
			for(int j=0;j<5;j++)
				arr[j][i*4+3]=1;
			break;
		case 8:
			arr[1][i*4+1]=1,arr[3][i*4+1]=1;
			for(int j=0;j<5;j++)
				arr[j][i*4+3]=1;
			break;
		case 9:
			arr[1][i*4+1]=1,arr[3][i*4+1]=1,arr[3][i*4]=1;
			for(int j=0;j<5;j++)
				arr[j][i*4+3]=1;
			break;
		case 0:
			arr[1][i*4+1]=1,arr[2][i*4+1]=1,arr[3][i*4+1]=1;
			for(int j=0;j<5;j++)
				arr[j][i*4+3]=1;
			break;
		
		}
	}
	
	
	
	
	for(int j=0;j<5;j++)
	{
		for(int i=0;i<4*n-1;i++)
		{
			if(!arr[j][i])
				cout<<'X';
			else
				cout<<'.';
		}
		cout<<endl;
	}
	
	return 0;
}
