/************************************
||    Author: Modest_xiaofeng      ||
||   Date: 2024-08-12 16:52:42     ||
|| Operating system: Ubuntu 22.04  ||
||         Editor: Vim             ||
||       QQ: 3198133420            ||
************************************/

#include<stdio.h>
#include<string.h>
#define lowbit(x) x&(-x)

int N, m;

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

void plus(int *num, int n, int m)
{
    int temp = 0;
    num[n - 1] += m;
    for(int i = 1; i < n; i++)
    {
        temp = num[n - i] / (i + 1);
        num[n - i] = num[n - i] % (i + 1);
        num[n - 1 - i] += temp;
    };
};

// 采用树状数组、变进制数来解决

int main(int argc, char *argv []) {

    scanf("%d %d", &N, &m);
    int TreeArr[N + 1], num[N], xixi = 0;
    memset(TreeArr, 0, (N + 1) * sizeof(int));

    for(int i = 1; i <= N; i++)
    {
        add(TreeArr, i, 1); // 建立树状数组
        xixi ^= i; // xixi用来检测最后剩余的数
    };

    int temp = 0;
    for(int i = 1; i < N; i++)
    {
        scanf("%i", &temp);
        num[i] = query(TreeArr, temp - 1); // 得出当前数字是从左到右第几个
        add(TreeArr, temp, -1); // 取出取出过的数字在树状数组的标记-1
    };
    scanf("%d", &temp);
    add(TreeArr, temp, -1);

    plus(num, N, m); // 变进制数加法

    for(int i = 1; i < N; i++) // 变进制数还原
    {
        temp = 0;
        for(int j = 1;; j++)
        {
            if(!TreeArr[j])
                temp++;
            if(temp - 1 == num[i])
            {
                TreeArr[j] = 1;
                printf("%d ", j);
                xixi ^= j;
                break;
            };
        };
    };
    printf("%d\n", xixi);

    return 0;
}

