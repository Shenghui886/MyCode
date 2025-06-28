//P5725 【深基4.习8】求三角形

#include<iostream>
using namespace std;

int main() {
	
	int n;cin>>n;
	for(int i=1;i<=n*n;i++)
	{
		if(i<10)
			printf("0%d",i);
		else
			printf("%d",i);
		if(i%n==0)
			printf("\n");
	}
	cout<<endl;
	int count=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
			printf("  ");
		for(int j=1;j<=i;j++)
		{
			if(count<10)
				printf("0%d",count++);
			else
				printf("%d",count++);
		}
		printf("\n");
	}
	
	
	return 0;
}
