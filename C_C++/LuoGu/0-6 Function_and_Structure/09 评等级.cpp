//P5742 【深基7.例11】评等级

#include<iostream>
using namespace std;

// 定义一个学生的数据类型
struct student
{
	int id; // 学号
	int Xscore; // 学业成绩
	int Zscore; // 素质拓展成绩
	
	//成员函数返回综合成绩
	int all(int xscore,int zscore)
	{
		return xscore * 7 + zscore * 3;
	}
};

// 判断该学生是否优秀
bool J(int all , int plu)
{
	if(all >= 800 && plu > 140)
		return true;
	else 
		return false;
}

int main() {
	
	int n;cin >> n;
	// 实例化一个学生数组
	student stu[n];
	
	//循环遍历，判断该学生是否优秀
	for(int i = 0;i < n;i++)
	{
		cin >> stu[i].id >> stu[i].Xscore >> stu[i].Zscore ;
		if(J( stu[i].all(stu[i].Xscore , stu[i].Zscore) , stu[i].Xscore + stu[i].Zscore))
			cout << "Excellent" << endl;
		else
			cout << "Not excellent" << endl;
	}
	
	
	return 0;
}
