//P1307 [NOIP2011 普及组] 数字反转
#include<iostream>
using namespace std;

int main() {
	
	int n,temp1,temp2=0;
	cin>>n;
	temp1=abs(n);
	if(n)
	{
		while(temp1%10==0)
			temp1/=10;
		while(temp1)
		{
			temp2*=10;
			temp2+=temp1%10;
			temp1/=10;
		}
		if(n<0)
			cout<<0-temp2<<endl;
		else
			cout<<temp2<<endl;
	}
	else
		cout<<0<<endl;
	
	system("pause");
	
	return 0;
}
