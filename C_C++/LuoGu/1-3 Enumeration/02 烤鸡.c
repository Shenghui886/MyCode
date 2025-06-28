// P2089 烤鸡

#include<stdio.h>  

#define f(a) for(int a = 1; a <= 3; a++)
int main()  
{  
	int a,b,c,d,e,f,g,h,i,j,in,x=0;
	
	scanf("%d", &in);
	
	f(a) f(b) f(c) f(d) f(e) f(f) f(g) f(h) f(i) f(j) 
		if (a+b+c+d+e+f+g+h+i+j == in)
			x++;
	
	printf("%d\n", x);
	
	f(a) f(b) f(c) f(d) f(e) f(f) f(g) f(h) f(i) f(j) 
		if (a+b+c+d+e+f+g+h+i+j == in) 
			printf("%d %d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i,j);
}  
