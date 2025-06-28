//P1177 【模板】排序

#include<iostream>
using namespace std;

int a[100000], b[100000], c[100000];

void qsort(int arr[], const int L, const int R)
{
	if(L >= R)
		return;
//	int pivot = L + rand()%(R - L + 1);
	int pivot = L + (R - L) / 2;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	
	for(int i = L; i <= R; i++)
	{
		if(arr[i] < arr[pivot])
			a[cnt1++] = arr[i];
		else if (arr[i] == arr[pivot])
			b[cnt2++] = arr[i];
		else
			c[cnt3++] = arr[i];
	}
	
	for(int i = 0; i < cnt1; i++)
		arr[i + L] = a[i];
	for(int i = 0; i < cnt2; i++)
		arr[cnt1 + i + L] = b[i];
	for(int i = 0; i < cnt3; i++)
		arr[cnt1 + cnt2 + i + L] = c[i];
	
	qsort(arr, L, L + cnt1 - 1);
	qsort(arr, R - cnt3 + 1, R);
	
	return;
	
}

int main(void) {
	
	int n;cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	qsort(arr, 0, n - 1);
	
	for(int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
	
	return 0;
}
