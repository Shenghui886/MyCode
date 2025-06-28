//P1009 [NOIP1998 普及组] 阶乘之和

//虽然这一题在之前的循环已经写过了
//但我还是觉得有必要优化一下
//之前写的东西太过冗余

//这题的本质是高精加 和 高精乘的结合

//用递归解决被加数的进位问题


#include<iostream>
using namespace std;

//-------------------高精加----------------------
void addition(int a[],int b[])
{
	for(int i = 0; i < 100 ; i++)
		a[i] += b[i];
	for(int i = 0;i < 100; i++)
		if(a[i] > 9)
		{
			a[i + 1] += a[i] / 10;
			a[i] = a[i] - a[i] / 10 * 10;
		}
}
//-----------------------------------------------

//-------------------高精乘----------------------
void multiple(int b[], int num)
{
	for(int i = 0;i < 100; i++)
		b[i] *= num;
	for(int i = 0;i < 100; i++)
		if(b[i] > 9)
		{
			b[i + 1] += b[i] / 10;
			b[i] = b[i] - b[i] / 10 * 10;
		}
}
//----------------------------------------------

int main() {
	
	int n;cin >> n;
	int a[100] = {1}, b[100] = {1};
	for(int i = 2; i <= n ; i++)
	{
		multiple(b , i);
		addition(a , b);
	}
	for(int i = 99 ; ; i--)
		if(a[i])
		{
			for(int j = i ; j >= 0 ;j--)
				cout << a[j] ;
			cout << endl;
			break;
		}
	
	return 0;
}
