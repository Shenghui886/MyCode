#include<stdio.h>
#define read(a) {char c; while((c = getchar()) > 47) a = (a << 3) + (a << 1) + (c ^ 48); if(c == '\r') getchar();}

int m, n;
int arr[20];

void dfs(int k, int min)
{
    if(k > n)
    {
        for(int i = 0; i < n; i++)
            printf("%3d", arr[i]);
        putchar('\n');
        return;
    }
    for(int i = min; i < m - n + k; i++)
    {
        arr[k - 1] = i + 1;
        dfs(k + 1, arr[k - 1]);
    }
}

int main(void) {

    scanf("%d %d", &m, &n);
    dfs(1, 0);

    return 0;
}
