#include<iostream>
#include<math.h>
using namespace std;

int main(void) {
	
	unsigned long long n, m, cnt = 0,temp1, temp2, temp3;
	long long deta1,deta2;
	double i;
	cin >> n >> m;
	//求根公式
	temp1 = (sqrt(4*m - 3) - 1.0) / 2.0; // 当b = 1时，a 的最大值
	//遍历a的可能值
	for(i = 1; i <= min(temp1, min(1000000llu, n)); i++)
	{
		deta1 = m / i - i + 0.25 / (i * i);
		deta2 = pow(i,2) + 4.0*(m / i - 1) / i;
		//求根公式，求b的最大值，也就是(a,b)时的个数
		if(deta1 > 0)
			temp2 = min((unsigned long long)((sqrt(deta1) - 0.5 / (i * i)) / i * i) , n);
		else temp2 = 0;
		//求根公式，求a的最大值，也就是(a,b)时的个数
		if(deta2 > 0)
			temp3 = min((unsigned long long)((sqrt(deta2) - i) / 2.0*i), n);
		else temp3 = 0;
		// a>b的个数 + b>a的个数
		if(temp2 > i)
			cnt += temp2 - i;
		if(temp3 > i)
			cnt += temp3 - i;
	}
	
	cout << cnt;	
	
	return 0;
}
