//用位运算判断n是不是2的整数次方

#include<iostream>
using namespace std;

int main() {
	
	int n;cin>>n;
	if(((n-1)&n)==0)
		cout<<n<<"是2的整数次方"<<endl;
	else
		cout<<n<<"不是2的整数次方"<<endl;
	
	return 0;
}
