//P5731 【深基5.习6】蛇形方阵

#include<iostream>
#include<iomanip>
using namespace std;

int arr[9][9];

int main() {
	
	int n;cin>>n;
	int x=0,y=0;
	int count=1;
	while(1)
	{
		for(;x<n && !arr[x][y];x++)
			arr[x][y]=count++;
		x--,y++;
		for(;y<n && !arr[x][y];y++)
			arr[x][y]=count++;
		y--,x--;
		for(;x>=0 && !arr[x][y];x--)
			arr[x][y]=count++;
		x++,y--;
		for(;y>=0 && !arr[x][y];y--)
			arr[x][y]=count++;
		y++,x++;
		if(count>n*n)
			break;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<setw(3)<<arr[j][i];
		cout<<endl;
	}
	
	return 0;
}
