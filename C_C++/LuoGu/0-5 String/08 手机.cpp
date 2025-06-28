//P1765 手机

#include<iostream>
using namespace std;

int arr[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

int main() {
	
	string str;getline(cin,str);
	int len=str.size(),count=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]==' ')
			count++;
		if(str[i]>='a'&&str[i]<='z')
			count+=arr[str[i]-'a'];
	}
	cout<<count<<endl;
	return 0;
}
