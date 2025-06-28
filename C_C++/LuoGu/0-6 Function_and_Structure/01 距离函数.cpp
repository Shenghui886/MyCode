//P5735 【深基7.例1】距离函数

#include<iostream>
#include<math.h>

using namespace std;

float C(float a1[2],float a2[2])
{
	return sqrt(pow(a1[0]-a2[0],2)+pow(a1[1]-a2[1],2));
}

int main() {
	
	float a1[2],a2[2],a3[2];
	cin>>a1[0]>>a1[1]>>a2[0]>>a2[1]>>a3[0]>>a3[1];
	printf("%.2f",C(a1,a2)+C(a2,a3)+C(a1,a3));
	
	return 0;
}
