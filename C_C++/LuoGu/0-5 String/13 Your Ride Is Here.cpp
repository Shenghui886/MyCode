//P1200 [USACO1.1] 你的飞碟在这儿 Your Ride Is Here

#include<iostream>
using namespace std;

int main() {
	
	string ufo;cin>>ufo;
	string peo;cin>>peo;
	int ul;ul=ufo.size();
	int pl;pl=peo.size();
	int us=1,ps=1;
	for(int i=0;i<ul;i++)
		us*=(ufo[i]-'A'+1);
	for(int i=0;i<pl;i++)
		ps*=(peo[i]-'A'+1);
	if((us%47)==(ps%47))
		cout<<"GO"<<endl;
	else
		cout<<"STAY"<<endl;
	
	return 0;
}
