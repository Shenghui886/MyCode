//P1042 [NOIP2003 普及组] 乒乓球

#include<iostream>
#include<math.h>
using namespace std;

int main() {
	
	string str = "";
	string str1;
	while(1)
	{
		cin >> str1;
		int pos = str1.find("E");
		if(pos!=-1)
		{
			str1=str1.substr(0,pos);
			str += str1;
			break;
		}
		else
			str += str1;
	}
	int len = str.size();
	int x = 0,y = 0,j = 1;
	for(int i = 0;i < len;i++)
	{
		if(str[i]=='W')
			x++;
		else
			y++;
		if((x >= 11 || y >= 11) && abs(x-y) >= 2 )
		{
			cout << x << ':' << y << endl;
			x = 0,y = 0;
			if(i == len - 1)
				cout << x << ':' << y << endl;
			j = !j;
		}
	}
	if(x || y || j)
	{
		cout << x << ':' << y << endl;
		x = 0,y = 0;
	}
	cout << endl;
	for(int i = 0;i < len;i++)
	{
		if(str[i]=='W')
			x++;
		else
			y++;
		if((x >= 21 || y >= 21) && abs(x-y) >= 2 )
		{
			cout << x << ':' << y << endl;
			x = 0,y = 0;
			if(i == len - 1)
				cout << x << ':' << y << endl;
		}
	}
	if(x || y || j)
	{
		cout << x << ':' << y << endl;
		x = 0,y = 0;
	}
	
	return 0;
}
