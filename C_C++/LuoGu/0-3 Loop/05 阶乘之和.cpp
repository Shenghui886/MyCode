//用高精度计算出 S=1!+2!+3!+⋯+n!（n≤50）
//本题要使用高精度的相关知识

#include<iostream>
using namespace std;

void judge(short arr[],int n)
{
	if(arr[n+1]+1<10)
	{
		arr[n+1]++;
		return;
	}
	else
	{
		arr[n+1]=0;
		judge(arr,n+1);
	}
}

int main() {
	
	int n;
	cin>>n;
	short arr[1000],sum[1000],temp[1000];
	//初始化数组
	for(int i=0;i<1000;i++)
	{
		arr[i]=-1;
		sum[i]=0;
	}
	arr[0]=1;
	sum[0]=1;
	
	//先temp数组清空
	//数组arr上的每一位数乘以阶乘的下一个数字，将结果保存再temp数组
	//再将temp数组上的数字复制到arr上，然后arr的数字加到sum里面
	for(int i=2;i<=n;i++)
	{
		for(int q=0;q<1000;q++)
 			temp[q]=0;
		int count_1=0,p;
		for(int j=0;arr[j]!=-1;j++)
		{
			int temp1;
			int mo=i;
			temp1=arr[j]*mo;
			for(p=count_1;temp1;p++,temp1/=10)
			{
				int momo=temp1%10;
				if(temp[p]+momo>=10)
				{
					temp[p]=temp[p]+momo-10;
					judge(temp,p);
				}
				else
					temp[p]+=momo;
			}
			count_1++;
		
		}
		for(int v=999;v>=0;v--)
		{
			if(temp[v]!=0)
			{
				for(int b=v;b>=0;b--)
					arr[b]=temp[b];
				break;
			}
		}
		for(int z=0;arr[z]!=-1;z++)
		{
			if(sum[z]+arr[z]>=10)
			{
				sum[z]=sum[z]+arr[z]-10;
				judge(sum,z);
			}
			else
				sum[z]=sum[z]+arr[z];
		}
		
	}
	
	for(int i=999;i>=0;i--)
	{
		if(sum[i]!=0)
		{
			for(int j=i;j>=0;j--)
				cout<<sum[j];
			cout<<endl;
			break;
		}
	}
	
	system("pause");
	
	return 0;
}
