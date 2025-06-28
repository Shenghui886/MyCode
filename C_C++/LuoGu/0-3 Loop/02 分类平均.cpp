#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n,k;
	double sum1=0,sum2=0,count1=0,count2=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		if(i%k==0)
		{
			sum1+=i;
			count1++;
		}
		else
		{
			sum2+=i;
			count2++;
		}
	}
	cout<<fixed<<setprecision(1)<<sum1/count1<<' '<<fixed<<setprecision(1)<<sum2/count2<<endl;
	
	system("pause");
	
	return 0;
}
