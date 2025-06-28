//P3741 honoka的键盘

#include<iostream>
using namespace std;

int main() {
	
	int n,pos,count=0,j=0;cin>>n;
	string str;cin>>str;
	for(int i=0;i<n;i++)
		str[i]=tolower(str[i]);
	
	for(int i=0;i<n;)
	{
		pos=str.find("vk",i);
		if(pos!=-1)
		{
			count++;
			str.erase(pos,2);
			str.insert(pos," ");
			i=pos+1;
		}
		else
		{
			pos=str.find("vv");
			if(pos!=-1)j=1;
			pos=str.find("kk");
			if(pos!=-1)j=1;
			break;
		}
	}
	if(j)count++;
	cout<<count<<endl;
	
	
	return 0;
}
