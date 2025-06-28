//P2911 [USACO08OCT] Bovine Bones G

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int arr[3];cin>>arr[0]>>arr[1]>>arr[2];
	//排序
	sort(arr,arr+3);
	//O(1)算法：
	if(arr[0]+arr[1]<=arr[2])
		cout<<arr[0]+arr[1]+1<<endl;
	else
		cout<<(arr[0]+arr[1]+arr[2]+3)/2<<endl;
	
	return 0;
}
