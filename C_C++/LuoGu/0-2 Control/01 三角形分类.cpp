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
	if(a+b<=c)
	{
		cout<<"Not triangle"<<endl;
	}
	else
	{
		if(pow(a,2)+pow(b,2)==pow(c,2))
		{
			if(a==b)
			{
				cout<<"Right triangle"<<endl;
				cout<<"Isosceles triangle"<<endl;
			}
			else
			{
				cout<<"Right triangle"<<endl;
			}
		}
		else if(pow(a,2)+pow(b,2)>pow(c,2))
		{
			if(a==b && a==c)
			{
				cout<<"Acute triangle"<<endl;
				cout<<"Isosceles triangle"<<endl;
				cout<<"Equilateral triangle"<<endl;
			}
			else if(a==b)
			{
				cout<<"Acute triangle"<<endl;
				cout<<"Isosceles triangle"<<endl;
			}
			else
			{
				cout<<"Acute triangle"<<endl;
			}
		}
		else
		{
			if(a==b)
			{
				cout<<"Obtuse triangle"<<endl;
				cout<<"Isosceles triangle"<<endl;
			}
			else
			{
				cout<<"Obtuse triangle"<<endl;
			}
		}
	}
	
	system("pause");
	
	return 0;
}
