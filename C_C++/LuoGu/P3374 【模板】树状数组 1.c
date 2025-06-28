/************************************
||    Author: Modest_xiaofeng      ||
||   Date: 2024-08-12 22:09:43     ||
|| Operating system: Ubuntu 22.04  ||
||         Editor: Vim             ||
||       QQ: 3198133420            ||
************************************/

#include<stdio.h>
#include<string.h>
int N, m;

int lowbit(int pos)
{
    return pos & (-pos);
};
void add(int *TreeArr, int pos, int x)
{
    while(pos <= N)
    {
        TreeArr[pos] += x;
        pos += lowbit(pos);
    };
};
int query(int *TreeArr, int pos)
{
    int result = 0;
    while(pos)
    {
        result += TreeArr[pos];
        pos -= lowbit(pos);
    };
    return result;
};

int main(int argc, char *argv []) {

    scanf("%d %d", &N, &m);
    int TreeArr[N + 1];
    memset(TreeArr, 0, (N + 1) * sizeof(int));
    for(int i = 1; i <= N; i++)
    {
        int temp = 0;
        scanf("%d", &temp);
        add(TreeArr, i, temp);
    };
    int a, x, y;
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &x, &y);
        if(a == 1)
            add(TreeArr, x, y);
        if(a == 2)
            printf("%d\n", query(TreeArr, y) - query(TreeArr, x - 1));
    };

    return 0;
}

