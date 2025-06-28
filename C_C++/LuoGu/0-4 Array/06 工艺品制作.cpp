//P5729 【深基5.例7】工艺品制作

#include<iostream>
using namespace std;

int main() {
	
	int w,x,h;cin>>w>>x>>h;
	int q;cin>>q;
	int arr[q][6];
	for(int i=0;i<q;i++)
		for(int j=0;j<6;j++)
			cin>>arr[i][j];
	int cube[w][x][h];
	for(int i=0;i<w;i++)
		for(int j=0;j<x;j++)
			for(int m=0;m<h;m++)
				cube[i][j][m]=1;
	for(int l=0;l<q;l++)
		for(int i=arr[l][0]-1;i<=arr[l][3]-1;i++)
			for(int j=arr[l][1]-1;j<=arr[l][4]-1;j++)
				for(int m=arr[l][2]-1;m<=arr[l][5]-1;m++)
					cube[i][j][m]=0;
	int count=0;
	for(int i=0;i<w;i++)
		for(int j=0;j<x;j++)
			for(int m=0;m<h;m++)
				if(cube[i][j][m])
					count++;
	cout<<count<<endl;
	
	return 0;
}
