//P5727 【深基5.例3】冰雹猜想

#include<iostream>
using namespace std;

int main() {
	
	int n,arr[1000],i=1;cin>>n;
	arr[0]=n;
	for(;n!=1;i++)
	{
		if(n%2)
			n=n*3+1,arr[i]=n;
		else
			n/=2,arr[i]=n;
	}
	for(;i>0;i--)
		cout<<arr[i-1]<<" ";
	cout<<endl;
	
	return 0;
}
