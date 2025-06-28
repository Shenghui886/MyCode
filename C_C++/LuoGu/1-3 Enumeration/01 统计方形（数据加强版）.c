// P2241 统计方形（数据加强版）

#include<stdio.h>

#define read(a){char c; while((c = getchar()) > 47) a = (a << 3) + (a << 1) + (c ^ 48); if(c == '\r')getchar();}

long long n, m;

int main(void) {
	
	read(n);
	read(m);
	
	long long suma = 0, sumb = 0;
	for(int i = 0; i < (n > m ? m : n); i++)
		suma += (n - i) * (m - i);
	
	sumb = (n * (n + 1) / 2) * (m * (m + 1) / 2) - suma;
	
	printf("%lld %lld\n", suma, sumb);
	
	return 0;
}
