/************************************
||    Author: Modest_xiaofeng      ||
||   Date: 2024-08-14 22:20:32     ||
|| Operating system: Ubuntu 22.04  ||
||         Editor: Vim             ||
||       QQ: 3198133420            ||
************************************/

#include<stdio.h>
#include<string.h>
#define MOD 998244353ll
#define lowbit(x) x&(-x)

int N;

void add(int *TreeArr, int pos, int x)
{
    for(int i = pos; i <= N; i += lowbit(i))
        TreeArr[i] += x;
};
int query(int *TreeArr, int pos)
{
    int sum = 0;
    for(int i = pos; i; i -= lowbit(i))
        sum += TreeArr[i];
    return sum;
};

int main(int argc, char *argv []) {

    scanf("%d", &N);
    int TreeArr[N + 1], Jc[N + 1];
    memset(TreeArr, 0, (N + 1) * sizeof(int));
    Jc[0] = 1;

    long long temp = 0;
    for(long long int i = 1; i <= N; i++)
    {
        Jc[i] = Jc[i - 1] * i % MOD;
        add(TreeArr, i, 1);
    };
    long long result = 0;
    for(int i = 1; i <= N; i++)
    {
        scanf("%lld", &temp);
        result += query(TreeArr, temp - 1) * 1ll * Jc[N - i];
        add(TreeArr, temp, -1);
        result %= MOD;
    };
    printf("%lld", (result + 1) % MOD);

    return 0;
}

