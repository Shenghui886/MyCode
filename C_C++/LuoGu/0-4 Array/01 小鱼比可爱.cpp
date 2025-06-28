//P1428 小鱼比可爱

#include<iostream>
using namespace std;

int main() {
	
	int n;cin>>n;
	int fish[n];for(int i=0;i<n;i++)cin>>fish[i];
	int arr[n];for(int i=0;i<n;i++)arr[i]=0;
	for(int i=n-1;i>0;i--)
		for(int j=i-1;j>=0;j--)
			if(fish[i]>fish[j])
				arr[i]++;
	for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	cout<<endl;

	return 0;
}
