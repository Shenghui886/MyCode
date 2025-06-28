/************************************
||    Author: Modest_xiaofeng      ||
||   Date: 2024-08-10 02:45:03     ||
|| Operating system: Ubuntu 22.04  ||
||         Editor: Vim             ||
||       QQ: 3198133420            ||
************************************/

#include<stdio.h>

struct
{
    char Ch;
    int times;
}arr[26];

int main(int argc, char *argv []) {

    char temp;
    
    while((temp = getchar()) != EOF)
        if(temp >= 'A' && temp <= 'Z')
            arr[temp - 'A'].times++;

    int max = 0;
    // 记录数据
    for(int i = 0; i < 26; i++)
        if(arr[i].times > max)
            max = arr[i].times;

    char Graph[max + 1][52];
    // 初始化
    for(int i = 0; i < max + 1; i++)
        for(int j = 0; j < 51; j++)
            Graph[i][j] = ' ';
    for(int i = 0; i < 26; i++)
        Graph[max][i * 2] = 'A' + i;
    Graph[max][51] = 0;

    // 绘图
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < arr[i].times; j++)
            Graph[max - j - 1][i * 2] = '*';
    for(int i = 0; i < max + 1; i++)
        for(int j = 50; j >= 0; j--)
            if(Graph[i][j] == '*')
            {
                Graph[i][j + 1] = 0;
                break;
            };

    // 输出
    for(int i = 0; i < max + 1; i++)
        printf("%s\n", Graph[i]);

    return 0;
}

