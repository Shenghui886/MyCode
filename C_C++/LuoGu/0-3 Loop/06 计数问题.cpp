//试计算在区间1 到 n 的所有整数中，数字x出现多少次
//经过优化代码，使时间复杂度达到了lg n。

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

#include<iostream>
using namespace std;

int main() {
	
	int m,n;cin>>m>>n;
	cout<<count(m,n);
	
	return 0;
}
