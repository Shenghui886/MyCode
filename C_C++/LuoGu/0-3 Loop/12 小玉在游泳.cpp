//P1423 小玉在游泳
//等比数列求和
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	
	double s;
	cin>>s;
	
	//函数：floor()向下取整  ceil向上取整
	cout<<ceil(log(1-s/100)/log(0.98))<<endl;
	
	system("pause");
	
	return 0;
}
