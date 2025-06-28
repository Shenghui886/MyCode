//P1308 [NOIP2011 普及组] 统计单词数

#include<iostream>
#include<string.h>
using namespace std;

int main() {
	
	string str1;cin>>str1;
	//ignore防止读取回车
	string str;cin.ignore(1);getline(cin,str);
	//提取两个字符串的长度
	int p=str.size(),q=str1.size();
	//两个for循环将所有字母变成小写
	for(int i=0;i<p;i++)
		if(str[i]>='A'&&str[i]<='Z')
			str[i]+='a'-'A';
	for(int i=0;i<q;i++)
		if(str1[i]>='A'&&str1[i]<='Z')
			str1[i]+='a'-'A';
	
//-------------------这一步是关键-----------------------
	//在输入的单词前后加一个空格，确保找到的不是单词里面的字母
	str1.insert(0," ");
	str1+=" ";
	//在句子前后加空格，防止查找时漏了开头和结尾两个单词
	str.insert(0," ");
	str+=" ";
//------------------------------------------------------
	//新单词的长度
	int n=str.size();
	//count用来储存找到的单词的个数
	int count=0;
	for(int i=0;i<n;i++)
	{
		int pos=str.find(str1,i);
		if(pos!=-1)
			count++,i=pos;
		else
			break;
	}
	if(count)
		cout<<count<<' '<<str.find(str1)<<endl;
	else 
		cout<<-1<<endl;
	
	return 0;
}
