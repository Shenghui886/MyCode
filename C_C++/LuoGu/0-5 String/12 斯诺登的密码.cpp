//P1603 斯诺登的密码

#include<iostream>
#include<algorithm>
using namespace std;

const string sarr[26]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","a","first","another","both","second","third"};
int arr[6];

int main() {
	
	string str;
	int num1[6];
	int count1=0;
	for(int j=0;j<6;j++)
	{
		cin>>str;
		for(int i=0;i<str.size();i++)
			str[i]=tolower(str[i]);
		for(int i=0;i<26;i++)
			if(sarr[i]==str)
			{
				if(i<20)
					num1[count1++]=((i+1)*(i+1))%100;
				else if(i<23)
					num1[count1++]=1;
				else if(i<25)
					num1[count1++]=4;
				else
					num1[count1++]=9;
			}
	}
	sort(num1,num1+count1);
	for(int i=0;i<count1;i++)
	{
		if(num1[i]<10)
		{
			if(i)
				cout<<0<<num1[i];
			else
				cout<<num1[i];
		}
		else
			cout<<num1[i];
	}
	if(!count1)
		cout<<0<<endl;

	cout<<endl;
	
	
	return 0;
}
