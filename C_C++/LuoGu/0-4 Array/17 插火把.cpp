//P1789 【Mc生存】插火把

#include<iostream>
using namespace std;

int arr[1000][1000];

//int arr[1000][1000];

int main() {
	
	int n,m,k;cin>>n>>m>>k;
	for(int i=0;i<m+k;i++)
	{
		int x,y;cin>>x>>y;
		if(i<m)
		{
			for(int j=x-1;j<x+4;j++)
				arr[j][y+1]=1;
			for(int j=y-1;j<y+4;j++)
				arr[x+1][j]=1;
			arr[x][y]=1;
			arr[x+2][y]=1;
			arr[x][y+2]=1;
			arr[x+2][y+2]=1;
		}
		else
		{
			for(int j=x+1;j<x+6;j++)
				for(int l=y+1;l<y+6;l++)
					arr[j][l]=1;
		}
	}
	int count=0;
	for(int i=2;i<n+2;i++)
		for(int j=2;j<n+2;j++)
			if(!arr[i][j])
				count++;
	cout<<count<<endl;
	
	return 0;
}
