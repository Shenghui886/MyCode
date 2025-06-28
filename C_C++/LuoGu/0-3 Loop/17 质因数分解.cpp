//P1075 [NOIP2012 普及组] 质因数分解
#include<iostream>
using namespace std;

//埃筛
void ai(int arr[])
{
	for(int i=0;i<=40000;i++)
	{
		if(arr[i])
		{
			arr[i]=i+2;
			for(int j=i*2+2;j<=40000;j+=i+2)
			{
				arr[j]=0;
			}
		}
	}
}

int main() {
	
	int n;cin>>n;
	static int arr[40000];
	for(int i=0;i<40000;i++)
		arr[i]=1;
	ai(arr);
	for(int i=0;i<40000;i++)
		if(arr[i])
			if(n%arr[i]==0) 
			{
				cout<<n/arr[i]<<endl;
				break;
			}

	return 0;
}
