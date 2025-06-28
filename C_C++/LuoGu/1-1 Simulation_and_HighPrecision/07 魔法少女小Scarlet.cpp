//P4924 [1007] 魔法少女小Scarlet

#include<iostream>
using namespace std;

int arr[500][500];
//旋转矩阵的子函数
void reverse(int &x, int &y, int &r, int &z)
{
	// 开辟临时数组，用来帮助旋转
	int temp[2*r+1][2*r+1];
	
	// 顺时针旋转
	if(!z)
		for(int i = x-r-1; i < x+r; i++)
			for(int j = y-r-1; j < y+r; j++)
				temp[j-(y-r-1)][2*r-i+(x-r-1)] = arr[i][j];
	
	// 逆时针旋转
	else
		for(int i = x-r-1; i < x+r; i++)
			for(int j = y-r-1; j < y+r; j++)
				temp[2*r-j+(y-r-1)][i-(x-r-1)] = arr[i][j];
	
	// 把被旋转的部分覆盖
	for(int i = x-r-1; i < x+r; i++)
		for(int j = y-r-1; j < y+r; j++)
			arr[i][j] = temp[i-(x-r-1)][j-(y-r-1)];
}

int main() {
	
	int n , m;cin >> n >> m;
	
	// 建立初始数组
	int count = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			arr[i][j] = count++;
	
	// 旋转
	int x, y, r, z;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y >> r >> z;
		reverse(x,y,r,z);
	}
	
	// 输出
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	
	return 0;
}
