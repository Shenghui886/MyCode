//P1720 月落乌啼算钱（斐波那契数列）
//斐波那契数的通项公式
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	cout<<fixed<<setprecision(2)<<(pow(((1+sqrt(5.0))/2.0),n)-pow(((1-sqrt(5.0))/2.0),n))/sqrt(5.0)<<endl;
	
	system("pause");
	
	return 0;
}
