//P1125 [NOIP2008 提高组] 笨小猴

#include<bits/stdc++.h>
using namespace std;

int arr[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main() {
	
	string str;cin>>str;
	int max=0,len=str.size(),min=len;
	
	//冒泡排序
	for(int i=0;i<len-1;i++)
		for(int j=0;j<len-1-i;j++)
			//新学的交换方法
			if(str[j]<str[j+1])
			{
				str[j]^=str[j+1];
				str[j+1]^=str[j];
				str[j]^=str[j+1];
			}
	
	int temp=1;
	for(int i=0;i<len-1;i++)
	{
		if(str[i+1]==str[i])
			temp++;
		else
		{
			if(temp<min)
				min=temp;
			if(temp>max)
				max=temp;
			temp=1;
		}
	}
	int num=max-min;
	for(int i=0;i<25;i++)
		if((num)==arr[i])
		{
			cout<<"Lucky Word"<<endl<<num<<endl;
			return 0;
		}
	cout<<"No Answer"<<endl<<0<<endl;
	
	
	return 0;
}
