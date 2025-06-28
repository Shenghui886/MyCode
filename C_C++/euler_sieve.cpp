#include<iostream>
#include<string.h>
using namespace std;

bool arr[100000];
int primes[100000];

//欧拉筛法，时间复杂度位O(n)
int euler()
{
	int k=0;
	arr[1]=0;
	memset(arr,true,sizeof(arr));
	
	for(int i=2;i<100000;i++)
	{
		if(arr[i])primes[++k]=i;
		for(int j=1;j<=k && primes[j]<=100000/i;j++)
		{
			arr[primes[j]*i]=0;
			if(i%primes[j]==0)break;
		}
	}
	return k;
}

int main() {
	
	int n=euler();
	for(int i=1;i<n;i++)
		cout<<primes[i]<<',';
	
	return 0;
}
