#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int x,n;
	cin>>x>>n;
	if(x<=5)
	{
		if(x+n%7-1>=7)
		{
			cout<<n/7*1250+(n%7-2)*250<<endl;
		}
		else if(x+n%7-1==6)
		{
			cout<<n/7*1250+(n%7-1)*250<<endl;
		}
		else
		{
			cout<<n/7*1250+n%7*250<<endl;
		}
	}
	else if(x==6)
	{
		if(n%7<=2)
		{
			cout<<n/7*1250<<endl;
		}
		else
		{
			cout<<n/7*1250+(n%7-2)*250<<endl;
		}
	}
	else
	{
		if(n%7<=1)
		{
			cout<<n/7*1250<<endl;
		}
		else
		{
			cout<<n/7*1250+(n%7-1)*250<<endl;
		}
	}
	
	system("pause");
	
	return 0;
}
