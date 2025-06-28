#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	double m;
	cin>>n;
	
	if(n>150)
	{
		if(n>400)
		{
			m=n*0.5663-40-3;
		}
		else
		{
			m=n*0.4663-3;
		}
	}
	else
	{
		m=n*0.4463;
	}
	
	
	cout<<fixed<<setprecision(1)<<m<<endl;
	
	system("pause");
	
	return 0;
}
