//P1303 A*B Problem

#include<iostream>
using namespace std;

short a[2000],b[2000],c[4001];

int main() {
	
	string A,B;
	cin >> A >> B;
	
	//----------特判----------
	if(A=="0" || B=="0")
	{
		cout << 0 << endl;
		return 0;
	}
	//------------------------
	
	int lena = A.size();
	int lenb = B.size();
	for(int i = 0; i < lena; i++)
		a[i] = A[i] - '0';
	for(int i = 0; i < lenb; i++)
		b[i] = B[i] - '0';
	
	for(int i = 0; i < lena; i++)
		for(int j = 0; j < lenb; j++)
			c[i + j] += a[i] * b[j];
	
	int lenc = lena + lenb - 1;
	for(int i = lenc - 1; i > 0 ; i--)
		if(c[i] > 9)
		{
			c[i - 1] += c[i] / 10;
			c[i] = c[i] - c[i] / 10 * 10;
		}
	for(int i = 0; i < lenc; i++)
		cout << c[i];
	
	return 0;
}
