//P1563 [NOIP2016 提高组] 玩具谜题

#include<iostream>
using namespace std;

struct smpeo
{
	bool dir; // 向里还是向外
	string name; // 小人的职业
};

struct order
{
	bool lor; // left or right
	int num; // 左边或右边多少个人
};

string find(smpeo num[] , order arr[] , int m , int n)
{
	int pos=0;
	for(int i = 0 ; i < n ; i++)
	{
		if(num[pos].dir) // 小人朝向圈外
		{
			if(arr[i].lor) // 小人右边
			{
				pos += m - arr[i].num;
				pos %= m;
			}
			else // 小人左边
			{
				pos += arr[i].num;
				pos %= m;
			}
		}
		else // 小人朝向圈内
		{
			if(arr[i].lor) // 小人右边
			{
				pos += arr[i].num;
				pos %= m;
			}
			else // 小人左边
			{
				pos += m - arr[i].num;
				pos %= m;
			}
		}
	}
	return num[pos].name;
}

int main() {
	
	int m, n;
	cin >> m >> n;
	
	// 创建小人数据类型
	smpeo num[m];
	for(int i = 0; i < m; i++)
		cin >> num[i].dir >> num[i].name;
	
	// 创建命令数据类型
	order arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i].lor >> arr[i].num;
	
	cout << find(num , arr , m , n) << endl;
	
	return 0;
}
