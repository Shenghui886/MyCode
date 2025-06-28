//极简代码，极快速度找出1~10落单那个数

#include<iostream>
using namespace std;

int main() {
	
	int n=0,temp;
	for(int i=0;i<19;i++)
		cin>>temp,n^=temp;
	cout<<n<<endl;
	
	return 0;
}
