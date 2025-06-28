//《庄子》中说到，“一尺之棰，日取其半，万世不竭”。第一天有一根长度为 a 的木棍，从第二天开始，每天都要将这根木棍锯掉一半（每次除2，向下取整）。第几天的时候木棍的长度会变为1？ 

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int a,count=1;
	cin>>a;
	while(a!=1)
	{
		a/=2;
		count++;
	}
	cout<<count<<endl;
	
	system("pause");
	
	return 0;
}

