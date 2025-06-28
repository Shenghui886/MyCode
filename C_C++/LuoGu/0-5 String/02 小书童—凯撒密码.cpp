//P1914 小书童——凯撒密码

#include<iostream>
using namespace std;

int main() {
	
	int n;cin>>n;
	string str;cin>>str;
	int len=str.size();
	for(int i=0;i<len;i++)
	{
		if(str[i]+n>'z')
			str[i]=(str[i]+n-'a')%26+'a';
		else
			str[i]+=n;
	}
	cout<<str<<endl;
	
	return 0;
}
