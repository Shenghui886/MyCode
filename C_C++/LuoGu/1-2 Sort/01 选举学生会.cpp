//P1271 【深基9.例1】选举学生会

#include<iostream>
using namespace std;

int main(void) {
	
	int n, m, x;cin >> n >> m;
	short num[n] = {0};
	for(int i = 0; i < m; i++)
	{
		cin >> x;
		num[x - 1]++;
	}
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < num[i]; j++)
			cout << i + 1 << ' ';
	cout << endl;
	
	return 0;
}

//#include<stdio.h>
//int main(void) {
//	
//	int n, m, x;
//	scanf("%d %d",&n, &m);
//	short num[n] = {0};
//	for(int i = 0; i < m; i++)
//	{
//		scanf("%d", &x);
//		num[x - 1]++;
//	}
//	for(int i = 0; i < n; i++)
//		for(int j = 0; j < num[i]; j++)
//			printf("%d ", i + 1);
//	
//	return 0;
//}
