//P5015 [NOIP2018 普及组] 标题统计

#include<iostream>
using namespace std;

int main() {
	
	string str;getline(cin,str);
	int count=0,len=str.size();
	for(int i=0;i<len;i++)
		if(str[i]!=' ')
			count++;
	cout<<count<<endl;
	
	return 0;
}
