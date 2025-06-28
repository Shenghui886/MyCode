#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int a,b,c,temp;
	cin>>a>>b>>c;
	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
		if(b>c)
		{
			temp=b;
			b=c;
			c=temp;
			if(a>b)
			{
				temp=a;
				a=b;
				b=temp;
			}
		}
	}
	else
	{
		if(b>c)
		{
			temp=b;
			b=c;
			c=temp;
			if(a>b)
			{
				temp=a;
				a=b;
				b=temp;
			}
		}
	}
	int num1=c,num2=a;
	//辗转相除法找最大公约数
	while(num1%num2!=0)
	{
		temp=num1%num2;
		num1=num2;
		num2=temp;
	}
	cout<<a/num2<<"/"<<c/num2<<endl;

	system("pause");
	
	return 0;
}
