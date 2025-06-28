// P1044 [NOIP2003 普及组] 栈

#include<stdio.h>

long long arr[20][20];

int main(void) {

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        arr[i][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    printf("%lld", arr[n][n]);

    return 0;
}

