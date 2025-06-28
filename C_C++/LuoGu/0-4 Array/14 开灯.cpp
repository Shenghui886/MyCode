//P1161 开灯
//这里考察了位运算（&、|、^、~、>>、<<）
//详见：https://www.runoob.com/w3cnote/bit-operation.html

#include<iostream>
using namespace std;

int main() {
	
	int n,ans=0,c;cin>>n;
	double a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(int j=1;j<=b;j++)
		{
			c=a*j;
			ans^=c;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
