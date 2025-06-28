//P1328 [NOIP2014 提高组] 生活大爆炸版石头剪刀布

#include<iostream>
using namespace std;

int vs[5][5] = {
	{0,0,1,1,0},
	{1,0,0,1,0},
	{0,1,0,0,1},
	{0,0,1,0,1},
	{1,1,0,0,0}
};

//算出最小公倍数
int minCM(int m, int n)
{
	int mn = m * n;
	int temp;
	while(n)
	{
		temp = m % n;
		m = n;
		n = temp;
	}
	return mn / m;
}

int main(void) {
	
	int n, a, b;cin >> n >> a >> b;
	int T = minCM(a, b);
	int Anum = 0,Bnum = 0, cnta = 0, cntb = 0;
	int arrA[a] ,arrB[b];
	for(int i = 0; i < a; i++)
		cin >> arrA[i];
	for(int i = 0; i < b; i++)
		cin >> arrB[i];
	if(n >= T)
		while(1)
		{
			if(arrA[cnta] - arrB[cntb])
			{
				if(vs[arrA[cnta]][arrB[cntb]])
					Anum++;
				else
					Bnum++;
			}
			cnta++,cntb++;
			if(cnta == a && cntb == b)
				break;
			if(cnta == a)
				cnta = 0;
			if(cntb == b)
				cntb = 0;
		}
	Anum *= n / T;
	Bnum *= n / T;
	cnta = 0;cntb = 0;
	for(int i = 0; i < n % T; i++)
	{
		if(arrA[cnta] - arrB[cntb])
		{
			if(vs[arrA[cnta]][arrB[cntb]])
				Anum++;
			else
				Bnum++;
		}
		cnta++,cntb++;
		if(cnta == a)
			cnta = 0;
		if(cntb == b)
			cntb = 0;
	}
	cout << Anum << ' ' << Bnum << endl;
	
	return 0;
}
