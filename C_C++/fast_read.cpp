#include<iostream>
using namespace std;
// 1、只识别正整数
#define read(a) {int c;while((c=getchar())>47) a=(a<<3)+(a<<1)+(c^48);}

//2、能识别负数

int main(void) {
	
	int a = 0;
	read(a);	
	cout << a << endl;
	
	return 0;
}
