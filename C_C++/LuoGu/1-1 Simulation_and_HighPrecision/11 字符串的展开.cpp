//P1098 [NOIP2007 提高组] 字符串的展开

#include<iostream>
using namespace std;

void print(int a, int b, int c, char ch0, char ch)
{
	int num = ch - ch0 - 1;
	if(num < 0)
		cout << '-';
	if(a == 3)
	{ 
		for(int i = 0; i < num * b; i++)
			cout << '*';
		return;
	}
	else if(a == 2)
	{
		if(ch >= 'a' && ch <= 'z')
		{
			ch += 'A' - 'a';
			ch0 += 'A' - 'a';
		}
	}
	else if(a == 1)
	{
		if(ch >= 'A' && ch <= 'Z')
		{
			ch += 'a' - 'A';
			ch0 += 'a' - 'A';
		}
	}
	if(c == 2)
	{
		for(int i = 1; i <= num; i++)
		{
			ch--;
			for(int j = 0; j < b; j++)
			{
				cout << ch;
			}
		}
	}
	else if(c == 1)
	{
		for(int i = 1; i <= num; i++)
		{
			ch0++;
			for(int j = 0; j < b; j++)
			{
				cout << ch0;
			}
		}
	}
}

int main() {
	
	int a, b, c; cin >> a >> b >> c;
	string str;cin >> str;
	int len = str.size();
	
	cout << str[0];
	for(int i = 1; i < len - 1; i++)
	{
		if(str[i] == '-')
		{
			if((str[i - 1] >='A' && str[i - 1] <='Z' && str[i + 1] >='A' && str[i + 1] <='Z') || (str[i - 1] >='a' && str[i - 1] <='z'&& str[i + 1] >='a' && str[i + 1] <='z') || (str[i - 1] >='0' && str[i - 1] <='9' && str[i + 1] >='0' && str[i + 1] <='9'))
				print(a, b, c, str[i - 1], str[i + 1]);
			else
				cout << '-';
		}
		else
			cout << str[i];
	}
	cout << str[len - 1];
	
	return 0;
}
