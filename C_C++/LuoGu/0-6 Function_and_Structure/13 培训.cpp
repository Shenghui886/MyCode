//P5744 【深基7.习9】培训

#include<iostream>
using namespace std;

struct student
{
	string name;
	int age;
	int score;
};

int main() {
	
	int n;cin >> n;
	student arr[n];
	for(int i = 0;i < n;i++)
	{
		cin >> arr[i].name >> arr[i].age >> arr[i].score;
		if(arr[i].score*1.2 <= 600)
			cout << arr[i].name << ' ' 
			<< arr[i].age+1 << ' ' 
			<< arr[i].score*1.2 << endl;
		else
			cout << arr[i].name << ' ' 
			<< arr[i].age+1 << ' ' 
			<< 600 << endl;
	}
	
	return 0;
}
