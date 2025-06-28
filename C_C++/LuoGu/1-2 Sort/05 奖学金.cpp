#include<iostream>
#include<algorithm>
using namespace std;

struct stu
{
	short id;
	short chi;
	short math;
	short eng;
	short sum;
};

bool cmp_score(stu x,stu y){
	if(x.sum < y.sum)
		return false;
	if(x.sum == y.sum)
	{
		if(x.chi < y.chi)
			return false;
	}
	return true;
}


int main(void) {
	
	int n;
	cin >> n;
	stu arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i].chi >> arr[i].math >> arr[i].eng;
		arr[i].id = i + 1;
		arr[i].sum = arr[i].chi + arr[i].math + arr[i].eng;
	}
	sort(arr, arr + n, cmp_score);
	
	for(int i = 0; i < 5; i++)
		cout << arr[i].id << ' ' << arr[i].sum << endl;
		
	return 0;
}
