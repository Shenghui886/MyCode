//P1597 语句解析

#include<iostream>
using namespace std;
int a[3];char s1,s2;

int main()
{
	while (scanf("%c:=%c;",&s1,&s2)==2)//看不懂
		a[s1-'a']=s2>='0' && s2<='9' ? s2-'0' : a[s2-'a']; //精髓
	printf("%d %d %d",a[0],a[1],a[2]);
}
