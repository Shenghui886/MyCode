#include<bits/stdc++.h>
using namespace std;

int main() {
	
	string ISBN;
	cin>>ISBN;
	int arr[10];
	for(int i=0,n=0;i<13;i++)
	{
		if(ISBN[i]=='-')
		{ 
			n++;
			continue;
		}
		if(ISBN[i]!='X')
			arr[i-n]=ISBN[i]-'0';//把字符串数字转化为整型
		else
			arr[i-n]=10;
	}
	int sum=0;
	for(int i=0;i<9;i++)
	{
		sum+=(i+1)*arr[i];
	}
	if(sum%11==arr[9])
	{
		cout<<"Right"<<endl;
	}
	else
	{
		for(int i=0;i<12;i++)
		{
			cout<<ISBN[i];
		}
		if(sum%11!=10)
			cout<<sum%11<<endl;
		else
			cout<<'X'<<endl;
	}
	
	system("pause");
	
	return 0;
}
