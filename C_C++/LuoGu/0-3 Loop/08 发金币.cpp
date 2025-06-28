//P2669 [NOIP2015 普及组] 金币

//时间复杂度为0

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	long long int i,k,sum=0;
	cin>>k;
	if(int(pow(2*k,0.5)-0.5)==pow(2*k,0.5)-0.5)
		i=int(pow(2*k,0.5)-0.5);
	else
		i=int(pow(2*k,0.5)-0.5)+1;
	sum+=i*(i+1)*(2*i+1)/6-(i*(i+1)/2-k)*i;
	cout<<sum<<endl;
	
	system("pause");
	
	return 0;
}
