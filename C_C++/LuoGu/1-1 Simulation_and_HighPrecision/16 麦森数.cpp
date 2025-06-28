//P1045 [NOIP2003 普及组] 麦森数

#include<iostream>
#include<math.h>
using namespace std;

//2^280;
int a[501] = {2}, b[501];


void multi(int a[])
{
	for(int j = 0; j < 500; j++)
	{
		for(int i = 0; i < 500; i++)
			b[i + j] += a[i] * a[j];
		for(int i = j; i < 500; i++)
		{
			b[i + 1] += b[i] / 10;
			b[i] %= 10; 
		}
		a[500] = 0;
		b[500] = 0;
	}
	for(int i = 0; i < 500; i++)
	{
		a[i] = b[i];
		b[i] = 0;
	}
}

void multi(int m)
{
	for(int i = 0; i < 500; i++)
		a[i] *= m;
	for(int i = 0; i < 500; i++)
	{
		a[i + 1] += a[i] / 10;
		a[i] %= 10; 
	}
	a[500] = 0;
}

void dg(int n)
{
	if(n == 1)
		return;
	
	if(n & 1)
	{
		dg(n >> 1);
		multi(a);
		multi(2);
	}
	else
	{
		dg(n >> 1);
		multi(a);
	}
}

int main() {
	
	int P;cin >> P;
	int num = ceil(P*log10(2));
	cout << num << endl;
	
	dg(P);
	a[0]--;
	for(int i = 499; i >= 0; i--)
	{
		cout << a[i];
		if(i % 50 == 0)
			cout << endl;
	}
	
	return 0; 
}
