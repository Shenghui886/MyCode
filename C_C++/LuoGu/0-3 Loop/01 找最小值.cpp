#include<bits/stdc++.h>
using namespace std;

//快速排序算法实现
void quicksort(int arr[],int L,int R)
{
	if(L>=R)
	{
		return;
	}
	int left=L,right=R,pivot=arr[left];
	while(left!=right)
	{
		while(arr[right]>=pivot && right>left)
		{
			right--;
		}
		if(left<right)
		{
			arr[left]=arr[right];
		}
		while(arr[left]<=pivot && right>left)
		{
			left++;
		}
		if(left<right)
		{
			arr[right]=arr[left];
		}
		if(left==right)
		{
			arr[left]=pivot;
		}
		quicksort(arr,L,right-1);
		quicksort(arr,left+1,R);
	}
}

int main() {
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	quicksort(arr,0,n-1);
	
	cout<<arr[0]<<endl;
	
	system("pause");
	
	return 0;
}
