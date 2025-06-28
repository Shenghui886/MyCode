//给出 n，请输出一个直角边长度是 n 的数字直角三角形。所有数字都是 2 位组成的，如果没有 2 位则加上前导 0

#include<iostream>
using namespace std;

int main() {
	
	int n,count=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(count<10)
			{
				printf("0%d",count);
			}
			else
			{
				cout<<count;
			}
			count++;
		}
		cout<<endl;
	}
	
	system("pause");
	
	return 0;
}
