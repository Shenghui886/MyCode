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
	int arr[3]={a,b,c};
	string ABC;
	cin>>ABC;
	cout<<arr[ABC[0]-'A']<<" "<<arr[ABC[1]-'A']<<" "<<arr[ABC[2]-'A']<<endl;
	
	
	system("pause");
	
	return 0;
}


