//P5736 【深基7.例2】质数筛

#include<iostream>
#include<string.h>
using namespace std;

bool arr[100000];
int primes[100000];

//欧拉筛法，时间复杂度位O(n)
//运行不了是编译器的问题(╯▔皿▔)╯
void euler()
{
	int k=0;
	memset(arr,true,sizeof(arr));
	arr[1]=0;
	for(int i=2;i<100000;i++)
	{
		if(arr[i])primes[k++]=i;
		for(int j=0;j<=k && primes[j]<=100000/i;j++)
		{
			arr[primes[j]*i]=0;
			if(i%primes[j]==0)break;
		}
	}
}
//这个能运行，本质上二者是一样的，(╯▔皿▔)╯
//void euler()
//{
//	int k=0;
//	memset(arr,true,sizeof(arr));
//	
//	for(int i=2;i<100000;i++)
//	{
//		if(arr[i])
//			primes[++k]=i;
//		for(int j=1;j<=k && primes[j]<=100000/i;j++)
//		{
//			arr[primes[j]*i]=0;
//			if(i%primes[j]==0)break;
//		}
//	}
//}

int main() {
	
	euler();
	int n;cin>>n;
	int num[n];
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		if(arr[num[i]])
			cout<<num[i]<<' ';
	}

	return 0;
}
