//P1786 帮贡排序

#include<iostream>
using namespace std;

void swap(string &a, string &b)
{
	string temp;
	temp = a;
	a = b;
	b = temp;
}

void swap(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

struct Team
{
	string name;
	string state;
	int contribution;
	int rate;
	
	void sw(Team &a)
	{
		swap(name, a.name);
		swap(contribution, a.contribution);
		swap(rate, a.rate);
	}
	
};

int main(void) {
	
	int n;cin >> n;
	Team arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i].name >> arr[i].state >> arr[i].contribution >> arr[i].rate;
	
	cout << arr[0].name << " BangZhu " << arr[0].rate << endl;
	
	for(int i = 1; i < 3; i++)
	{
		for(int j = 2; j > 1; j--)
			if(arr[j].rate > arr[j - 1].rate)
				arr[j].sw(arr[j - 1]);
		cout << arr[i].name << " FuBangZhu " << arr[i].rate << endl;
	}
	
	for(int i = 3; i < n - 1; i++)
		for(int j = 3; j < n - i + 2; j++)
			if(arr[j].contribution < arr[j + 1].contribution)
				arr[j].sw(arr[j + 1]);
	
	int i = 3;
	for(;i < 5 && i < n; i++)
	{
		for(int j = min(4, n-1); j > 3; j--)
			if(arr[j].rate > arr[j - 1].rate)
				arr[j].sw(arr[j - 1]);
		cout << arr[i].name << " HuFa " << arr[i].rate << endl;
	}
	for(;i < 9 && i < n; i++)
	{
		for(int j = min(8, n-1); j > 5; j--)
			if(arr[j].rate > arr[j - 1].rate)
				arr[j].sw(arr[j - 1]);
		cout << arr[i].name << " ZhangLao " << arr[i].rate << endl;
	}
	for(;i < 16 && i < n; i++)
	{
		for(int j = min(15, n-1); j > 9; j--)
			if(arr[j].rate > arr[j - 1].rate)
				arr[j].sw(arr[j - 1]);
		cout << arr[i].name << " TangZhu " << arr[i].rate << endl;
	}
	for(;i < 41 && i < n; i++)
	{
		for(int j = min(40, n-1); j > 16; j--)
			if(arr[j].rate > arr[j - 1].rate)
				arr[j].sw(arr[j - 1]);
		cout << arr[i].name << " JingYing " << arr[i].rate << endl;
	}
	for(;i < n; i++)
	{
		for(int j = n - 1; j > 41; j--)
			if(arr[j].rate > arr[j - 1].rate)
				arr[j].sw(arr[j - 1]);
		cout << arr[i].name << " BangZhong " << arr[i].rate << endl;
	}
	
	
	return 0;
}
