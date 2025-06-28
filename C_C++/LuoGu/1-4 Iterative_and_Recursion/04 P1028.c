// P1028 [NOIP2001 普及组] 数的计算

#include<stdio.h>

int arr[1010];

int main(void) {

    int n;
    scanf("%d", &n);
    arr[1] = 1, arr[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        for(int j = 1; j <= i / 2; j++)
            arr[i] += arr[j];
        arr[i]++;
    }
    printf("%d\n", arr[n]);


    return 0;
}

