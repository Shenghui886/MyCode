//运用&与运算
//找出n的二进制的1的个数

#include<iostream>
using namespace std;

int main() {
	
	int n,count=0;cin>>n;
	while(n)
	{
		if(n&1)
			count++;
		n>>=1;//右移运算符
	}
	cout<<count<<endl;
	
	return 0;
}
