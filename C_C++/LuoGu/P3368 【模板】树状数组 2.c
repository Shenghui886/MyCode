/************************************
||    Author: Modest_xiaofeng      ||
||   Date: 2024-08-13 16:12:19     ||
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

    int temp1 = 0, temp2 = 0;
    scanf("%d", &temp2);
    add(TreeArr, 1, temp2);
    for(int i = 2; i <= N; i++)
    {
        scanf("%d", &temp1);
        add(TreeArr, i, temp1 - temp2);
        temp2 = temp1;
    };
    int b, x, y, k;
    for(int i = 0; i < m; i++)
    {
        scanf("%i", &b);
        if(b == 1)
        {
            scanf("%i %i %i", &x, &y, &k);
            add(TreeArr, x, k);
            add(TreeArr, y + 1, -k);
        };
        if(b == 2)
        {
            scanf("%i", &x);
            printf("%i\n", query(TreeArr, x));
        };
    };

    return 0;
}

















