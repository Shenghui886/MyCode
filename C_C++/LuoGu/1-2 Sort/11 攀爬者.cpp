// P5143 攀爬者

#include<stdio.h>
#include<cmath>
#include<algorithm>

#define read(a) {char c; while((c = getchar()) > 47) a = (a << 3) + (a << 1) + (c ^ 48); if(c == '\r')getchar();}

using namespace std;

struct xyz {
	int x;
	int y;
	int z;
};

bool cmp(xyz a, xyz b)
{
	return a.z < b.z;
}

int main(void) {
	
	int n = 0; read(n);
	double sum = 0.;
	xyz arr[50000] = {{0, 0, 0}};
	
	for(int i = 0; i < n; i++) {read(arr[i].x); read(arr[i].y); read(arr[i].z);}
	
	sort(arr, arr + n, cmp);
	
	for(int i = 0; i < n - 1; i++)
		sum += sqrt(pow(arr[i].x - arr[i + 1].x, 2) + pow(arr[i].y - arr[i + 1].y, 2) + pow(arr[i].z - arr[i + 1].z, 2));
	
	printf("%.3lf\n", sum);
	
	return 0;
}
