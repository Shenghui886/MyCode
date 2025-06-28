//P1249 最大乘积

#include<iostream>
#include<math.h>
using namespace std;

//高精乘
void mul(int num, int Array[])
{
	for(int i = 0; i < 1000; i++)
		Array[i] *= num;
	for(int i = 0; i < 1000; i++)
	{
		Array[i + 1] += Array[i] / 10;
		Array[i] %= 10; 
	}
}

int main() {
	
	int n, num;
	cin >> num;
	
	//通过公式计算出数组长度
	n = sqrt(num * 2 + 2.25) - 1.5;
	int arr[n];
	
	//乘过后的结果
	int Array[1000] = {1};
	
	//初始化数组
	for(int i = 2; i < n + 2; i++)
		arr[i - 2] = i;
	
	//多出的数
	int yu = num - (n + 3) * n / 2;
	
	//多出的数和数组中某个值相加
	if(arr[n - 1] - 1 <= yu)
		arr[0] += yu;
	else
		arr[arr[n - 1] - yu - 1] += yu;
	
	//重新排序
	for(int i = 0; i < n - 1; i++)
		if(arr[i] > arr[i + 1])
			swap(arr[i], arr[i + 1]);
	
	//输出结果
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
		mul(arr[i], Array);
	}
	cout << endl;
	
	for(int i = 999; i >= 0; i--)
		if(Array[i])
		{
			for(int j = i; j >= 0; j--)
				cout << Array[j];
			cout << endl;
			break;
		}
	
	return 0;
}
