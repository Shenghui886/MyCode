//不用额外的辅助储存空间，找出11个1~10内的数中重复的数，1~10都至少出现过一次。
//运用异或运算
#include<iostream>
using namespace std;

int main() {
	
	int a=0,temp;
	for(int i=1;i<=10;i++)
		a^=i;//异或运算符
	for(int i=0;i<11;i++)
		cin>>temp,a^=temp;
	cout<<a<<endl;
	
	return 0;
}
