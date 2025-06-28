//P1321 单词覆盖还原

#include<iostream>
using namespace std;

int J(string *str,string sub)
{
	int pos=0,count=0;
	while(1)
	{
		pos=str->find(sub,pos);
		if(pos!=-1)
		{
			str->erase(pos,sub.size());
			str->insert(pos,".");
			pos+=1;
			count++;
		}
		else
			break;
	}
	return count;
}

int main() {
	
	string str;cin>>str;
	string boy="boy",gril="girl";
	int sum=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<=i;j++)
			sum+=J(&str,boy.substr(j,3-i));
	cout<<sum<<endl;
	sum=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<=i;j++)
			sum+=J(&str,gril.substr(j,4-i));
	cout<<sum<<endl;
	
	return 0;
}
/*
int main() {
	int boy=0,girl=0;  //boy和girl用来记下各自的个数 
	string str;  //定义题目给出的字符串 
	cin>>str;  //这个我们校长都能看得懂的输入~ 
	for(int i=0;i<=str.length();i++)
	{
		if (str[i]=='b'||str[i+1]=='o'||str[i+2]=='y')
			boy++;
		if (str[i]=='g'||str[i+1]=='i'||str[i+2]=='r'||str[i+3]=='l')
			girl++;
	}
	cout<<boy<<endl;
	cout<<girl<<endl;

	return 0;
}
*/
