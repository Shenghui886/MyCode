//P5726 【深基4.习9】打分
#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n;cin>>n;
	int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	double sum=0;
	for(int i=1;i<n-1;i++)
		sum+=arr[i];
	cout<<fixed<<setprecision(2)<<sum/(n-2)<<endl;
	
	return 0;
}
