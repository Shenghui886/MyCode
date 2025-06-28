//P5739 【深基7.例7】计算阶乘

#include<iostream>
using namespace std;
int J(int n)
{
	if(n==1)
		return 1;
	return n*J(n-1);
}

int main() {
	
	int n;cin>>n;
	cout<<J(n)<<endl;
	
	return 0;
}
