//P2615 [NOIP2015 提高组] 神奇的幻方

#include<iostream>
using namespace std;

int arr[40][40];

//借鉴大佬的厉害方法：
int main() {
	
	int n;cin>>n;
	int x=0,y=n/2;
	for(int i=1;i<=n*n;i++)
	{
		arr[x][y]=i;
		if(!arr[(x-1+n)%n][(y+n+1)%n])
			x=(x-1+n)%n,y=(y+n+1)%n;
		else
			x-=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<' ';
		cout<<endl;
	}
	
	return 0;
}



//低调小冯的垃圾递归

/*
void H(int arr[39][39],int *K,int N,int x,int y)
{
	if(*K>=N*N)
		return;
	if(x==0 && y!=N-1)
	{
		arr[N-1][y+1]=++(*K);
		H(arr,K,N,N-1,y+1);
	}
	else if(x!=0 && y==N-1)
	{
		arr[x-1][0]=++(*K);
		H(arr,K,N,x-1,0);
	}
	else if(x==0 && y==N-1)
	{
		arr[1][N-1]=++(*K);
		H(arr,K,N,1,N-1);
	}
	else
	{
		if(arr[x-1][y+1])
		{
			arr[x+1][y]=++(*K);
			H(arr,K,N,x+1,y);
		}
		else
		{
			arr[x-1][y+1]=++(*K);
			H(arr,K,N,x-1,y+1);
		}
	}
}


int main() {
	
	int arr[39][39],N;cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			arr[i][j]=0;
	arr[0][N/2]=1;
	int x=0,y=N/2,K=1;
	H(arr,&K,N,x,y);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<arr[i][j]<<' ';
		cout<<endl;
	}
	
	return 0;
}
*/
