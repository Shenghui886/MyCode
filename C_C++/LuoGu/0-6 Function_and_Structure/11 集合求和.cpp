//P2415 集合求和

#include<iostream>
using namespace std;

long long int arr[30];

int main() {
	
	int n = 0;
	unsigned long long sum = 0;
	
	//对未知数据量的数据读取进行处理
	while(cin >> arr[n++])
		if(cin.get() == '\n') // 碰到回车就退出
			break;
	
	for(int i = 0;i < n;i++)
	{
		if(n>=2)
			sum += arr[i] * (2<<(n-2));
		else
			sum += arr[i];
	}
	cout << sum << endl;
	
	return 0;
}
