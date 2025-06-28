//P5741 【深基7.例10】旗鼓相当的对手 - 加强版

#include<iostream>
#include<math.h>
using namespace std;

//定义一个学生数据类型
struct student
{
	string name;
	int chinese;
	int math;
	int english;
	int sum;
};

int main() {
	
	int n;
	cin >> n;
	
	//创建一个学生数组对象
	student arr[n];
	//输入数据
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i].name >> arr[i].chinese >> arr[i].math >> arr[i].english;
		arr[i].sum = arr[i].chinese + arr[i].math + arr[i].english;
	}
	
	//枚举比较并输出结果
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if(abs(arr[i].chinese - arr[j].chinese) <= 5 && abs(arr[i].math - arr[j].math) <= 5)
				if(abs(arr[i].english - arr[j].english) <= 5 && abs(arr[i].sum - arr[j].sum) <=10)
					cout << arr[i].name << ' ' << arr[j].name << endl;	
	
	return 0;
}

