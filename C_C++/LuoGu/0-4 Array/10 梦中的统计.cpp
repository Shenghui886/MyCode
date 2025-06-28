//P1554 梦中的统计

#include<iostream>
using namespace std;

int arr[10];

//计算数字从1-n中个数字x出现了多少次
int count(int n,int x)
{
	int temp=n,cnt=0,mo,count=1;
	if(!x)
	{
		while(temp/10)
		{
			mo=temp%10;
			temp/=10;
			if(mo)
				cnt+=temp*count;
			else
				cnt=cnt+(temp-1)*count+(n-temp*count*10+1);
			count*=10;
		}
		return cnt;
	}
	else
	{
		while(temp)
		{
			mo=temp%10;
			temp/=10;
			if(mo<x)
				cnt+=temp*count;
			else if(mo==x)
				cnt+=temp*count+n%count+1;
			else
				cnt+=(temp+1)*count;
			count*=10;
		}
		return cnt;
	}
}
int main() {
	
	int m,n;cin>>m>>n;
	
	for(int i=0;i<10;i++)
		arr[i]=count(n,i)-count(m-1,i);
	
	for(int i=0;i<10;i++)
		cout<<arr[i]<<' ';
	cout<<endl;
	
	return 0;
}
