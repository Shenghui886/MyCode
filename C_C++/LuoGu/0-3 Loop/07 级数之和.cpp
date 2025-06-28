//P1035 [NOIP2002 普及组] 级数求和

#include<iostream>
using namespace std;

int main() {
	
	double sum=0;
	int k,n=0;
	cin>>k;
	while(k>=sum)
	{
		sum+=1.0/++n;
	}
	cout<<n<<endl;
	
	system("pause");
	
	return 0;
}
