//P5733 【深基6.例1】自动修正

#include<iostream>

using namespace std;

int main() {
	
	string str(" ");
	getline(cin,str);
	int len=str.size();
	for(int i=0;i<len;i++)
		if(str[i]<='z'&&str[i]>='a')
			str[i]+='A'-'a';
	cout<<str<<endl;
	
	
	return 0;
}
