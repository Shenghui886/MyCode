//P1957 口算练习题

#include<iostream>
#include<string>
using namespace std;

int main() {
	
	int n;cin>>n;
	char ch;
	//cin.ignore(1)很重要！！！
	cin.ignore(1);
	string str[n];for(int i=0;i<n;i++)getline(cin,str[i]);
	
	for(int i=0;i<n;i++)
	{
		int len=str[i].size();
		int j=2;
		if(str[i][0]>='a'&&str[i][0]<='c')
			ch=str[i][0];
		else
			j=0;
		int num1=0,num2=0,count=2;
		
		for(;str[i][j]!=' ';j++)
		{
			num1*=10;
			num1+=str[i][j]-'0';
			count++;
		}
		j++;
		for(;j<len;j++)
		{
			num2*=10;
			num2+=str[i][j]-'0';
			count++;
		}
		int temp;
		if(num1==0)count++;
		if(num2==0)count++;
		if(ch=='a')
			temp=num1+num2;
		else if(ch=='b')
			temp=num1-num2;
		else if(ch=='c')
			temp=num1*num2;
		if(temp<=0)count++;
		while(temp)
		{
			temp/=10;
			count++;
		}
		if(ch=='a')
			cout<<num1<<'+'<<num2<<'='<<num1+num2<<'\n'<<count<<endl;
		else if(ch=='b')
			cout<<num1<<'-'<<num2<<'='<<num1-num2<<'\n'<<count<<endl;
		else
			cout<<num1<<'*'<<num2<<'='<<num1*num2<<'\n'<<count<<endl;
	}

		
	return 0;
}
