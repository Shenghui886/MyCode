//P4956 [COCI2017-2018#6] Davor

#include<iostream>
using namespace std;

int main() {
	
	int n;cin>>n;
	int x,k=1;
	n/=7*52;
	if(n-3>=100)
	{
		if(n%3==1)
		{
			x=100;
			k=(n-x)/3;
		}
		else if(n%3==2)
		{
			x=98;
			k=(n-x)/3;
		}
		else
		{
			x=99;
			k=(n-x)/3;
		}
	}
	else
		x=n-3;
	cout<<x<<endl<<k<<endl;
	
	return 0;
}
