//P5723 【深基4.例13】质数口袋

//一个高效算法:埃筛

#include<iostream>
using namespace std;

//用埃筛筛选出质数，而不是每一个去判断
//原理：如果n是质数，那么2n,3n,4n,...这些n的倍数肯定都不是质数。
void ai(int arr[],int n)
{
	int count=0,sum=0;
	if(n!=1)
	{
		for(int i=0;i<n;i++)
			arr[i]=1;
		for(int i=1;i<n;i++)
		{
			if(arr[i])
			{
				arr[i]=i+1;
				if(sum+arr[i]>n)
					break;
				cout<<arr[i]<<endl;
				count++,sum+=arr[i];
				for(int j=i;j<n;j+=(i+1))
				{
					arr[j]=0;
				}
			}
		}
		cout<<count<<endl;
	}
	else
		cout<<0<<endl;
}

int main() {
	
	int n;
	cin>>n;
	int *arr=new int[n];
	ai(arr,n);
	
	system("pause");
	
	return 0;
}
