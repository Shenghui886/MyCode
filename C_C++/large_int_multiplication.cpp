
//-----------------------------------------------
//-------------超级棒的思路，超级快--------------
//-----------------------------------------------

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char a1[10001], b1[10001];
int a[10001], b[10001], i, x, len, j, c[10001];
int main () {
	
	//处理数据
	cin >> a1 >> b1;//不解释，不懂看前面
	int lena = strlen(a1);//每个部分都很清楚
	int lenb = strlen(b1);//这只是方便你们复制
	for (i = 1; i <= lena; i++)
		a[i] = a1[lena - i] - '0';
	for (i = 1; i <= lenb; i++)
		b[i] = b1[lenb - i] - '0';
	
	
	for (i = 1; i <= lenb; i++)
		for (j = 1; j <= lena; j++)
			c[i + j - 1] += a[j] * b[i];
	for (i = 1; i < lena + lenb; i++)
		if (c[i] > 9) 
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	len = lena + lenb;
	while (c[len] == 0 && len > 1)
		len--;
	for (i = len; i >= 1; i--)
		cout << c[i];
	return 0;
}
