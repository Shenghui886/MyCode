//P1601 A+B Problem（高精）

#include<iostream>
using namespace std;

void addition(int a[], int b[], int add[])
{
	for(int i = 0; i < 501; i++)
		add[i] = a[i] + b[i];
	for(int i = 0; i < 500; i++)
		if(add[i] > 9)
		{
			add[i + 1]++;
			add[i] %= 10;
		}
}

int main() {
	
	int a[501] = {0},b[501] = {0},add[501] = {0};
	string n,m;
	cin >> n >> m;
	//特判
	if(n == "0" || m == "0")
	{
		cout << 0 << endl;
		return 0;
	}
	
	int nlen = n.size();
	int mlen = m.size();
	for(int i = 0 ; i < nlen ; i++)
		a[nlen - i - 1] = n[i] - '0';
	for(int i = 0 ; i < mlen ; i++)
		b[mlen - i - 1] = m[i] - '0';
	addition(a ,b , add);
	
	for(int i = 500; i >= 0 ;i--)
		if(add[i])
		{
			for(int j = i; j >= 0;j--)
				cout << add[j];
			cout << endl;
			break;
		}
	
	return 0;
}
