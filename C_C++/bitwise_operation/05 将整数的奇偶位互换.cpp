//将整数的奇偶位互换

#include<iostream>
using namespace std;
int main() {
	
	int x = 0;
	cin >> x;
	int ji = x & 0b10101010101010;//将数字和10101010.....与运算&得到奇数位
	int ou = x & 0b1010101010101;//将数字和01010101.....与运算&得到偶数位
	//将奇数位右移一位，偶数位左移一位，然后做异或运算^
	cout << ((ji >> 1) ^ (ou << 1));//这里^换成+也行
	
	return 0;
}
