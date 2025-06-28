//P5734 【深基6.例6】文字处理软件

//str.size();  返回str字符串的长度
//str.substr(pos,lenth);   返回一个子串，该子串从pos位置起，长度为lenth个字符
//str.insert(pos,str2);   将str插入str的pos位置处
//str.remove(pos,lenth);   从pos起，删除长度为lenth的子串
//str.find(strl);   返回strl首次在str中出现的位置

//string 类字符串有运算重载

#include<iostream>
using namespace std;

int main() {
	
	int n;cin>>n;
	string str;cin>>str;
	for(int i=0;i<n;i++)
	{
		int m;cin>>m;
		string s;
		switch (m) {
		case 1:
			cin>>s;
			str+=s;
			cout<<str<<endl;
			break;
		case 2:
			int p,q;cin>>p>>q;
			str=str.substr(p,q);
			cout<<str<<endl;
			break;
		case 3:
			int a;cin>>a;
			cin>>s;
			str.insert(a,s);
			cout<<str<<endl;
			break;
		case 4:
			cin>>s;
			int c=str.find(s);
			cout<<c<<endl;
			break;
		}
	}
	
	return 0;
}

