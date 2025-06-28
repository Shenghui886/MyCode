//P1553 数字反转（升级版）

#include<iostream>
using namespace std;

void R(string &str,int pos,int len)
{
	string str1=str.substr(pos,len);
	if(str1=="0")return;
	for(int i=0;i*2<len;i++)
	{
		char temp=str1[i];
		str1[i]=str1[len-1-i];
		str1[len-1-i]=temp;
	}
	int i=0;
	for(;i<len;i++)
		if(str1[i]-'0')
			break;
	str1=str1.substr(i,len-i);
	str.erase(pos,len);
	str.insert(pos,str1);
}

void Rt(string &str,int pos,int len)
{
	string str1=str.substr(pos,len);
	if(str1=="0")return ;
	for(int i=0;i*2<len;i++)
	{
		char temp=str1[i];
		str1[i]=str1[len-1-i];
		str1[len-1-i]=temp;
	}
	int i=len-1;
	for(;i>=0;i--)
		if(!(str1[i]-'0'))
			break;
	str1=str1.substr(0,i);
	str.erase(pos,len);
	str.insert(pos,str1);
}

int main() {
	
	string str;cin>>str;
	int n=str.size();
	int pos=0;
	for(;pos<n;pos++)
	{
		if(str[pos]=='.')
		{
			Rt(str,pos+1,n-pos-1);
			R(str,0,pos);
			break;
		}
		if(str[pos]=='%')
		{
			R(str,0,pos);
			break;
		}
		if(str[pos]=='/')
		{
			R(str,pos+1,n-pos-1);
			R(str,0,pos);
			break;
		}
	}
	if(pos==n)
		R(str,0,pos);
	cout<<str<<endl;
	
	return 0;
}
