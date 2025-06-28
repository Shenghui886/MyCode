//P5740 【深基7.例9】最厉害的学生
//------------用结构体-------------

#include<iostream>
using namespace std;

//创建一个学生数据类型
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
	
	//从键盘读取数据
	student arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i].name >> arr[i].chinese >> arr[i].math >> arr[i].english;
		arr[i].sum = arr[i].chinese + arr[i].math + arr[i].english;
	}
	
	//寻找总分最大的同学
	int pos=0;
	for(int i = 1; i < n; i++)
	{
		if(arr[pos].sum < arr[i].sum)
			pos = i;
	}
	
	//输出最终结果
	cout << arr[pos].name << ' ' 
	<< arr[pos].chinese << ' ' 
	<< arr[pos].math << ' ' 
	<< arr[pos].english;
	cout << endl;
	
	return 0;
}
//用结构体轻轻松松
