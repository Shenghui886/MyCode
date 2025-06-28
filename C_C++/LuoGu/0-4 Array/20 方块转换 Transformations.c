/************************************
||    Author: Modest_xiaofeng      ||
||   Date: 2024-08-09 16:56:28     ||
|| Operating system: Ubuntu 22.04  ||
||         Editor: Vim             ||
||       QQ: 3198133420            ||
************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n;

void GetData(bool** N, int n);
bool IsSame(bool** A, bool**B , int n);
bool** CreateMatrix(int n);
bool** TransPosition(bool** N, int n);
bool** TransUpDown(bool** N, int n);
bool** TransLeftRight(bool** N, int n);

int main(int argc, char *argv []) {

    scanf("%d", &n);
    getchar();
    getchar();
    
    bool** Square = CreateMatrix(n);
    bool** Answer = CreateMatrix(n);

    GetData(Square, n);
    GetData(Answer, n);

    if(IsSame(TransPosition(TransUpDown(Square, n), n), Answer, n))
        putchar('1');
    else if(IsSame(TransUpDown(TransLeftRight(Square, n), n), Answer, n))
        putchar('2');
    else if(IsSame(TransPosition(TransLeftRight(Square, n), n), Answer, n))
        putchar('3');
   else if(IsSame(TransLeftRight(Square, n), Answer, n))
        putchar('4');
    else if(
            IsSame(TransLeftRight(TransPosition(TransLeftRight(Square, n), n), n), Answer, n) || 
            IsSame(TransUpDown(Square, n), Answer, n) ||
            IsSame(TransLeftRight(TransPosition(TransUpDown(Square, n), n), n), Answer, n)
                )
        putchar('5');
    else if(IsSame(Square, Answer, n))
        putchar('6');
   else
        putchar('7');


    return 0;
}

bool** CreateMatrix(int n)
{
    bool** temp = malloc(n * sizeof(bool*));
    for(int i = 0; i < n; i++)
        temp[i] = malloc(n * sizeof(bool));
    return temp;
};

bool** TransPosition(bool** N, int n)
{
    bool** temp = CreateMatrix(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = N[j][i];
    return temp;
};

bool** TransUpDown(bool** N, int n)
{
    bool** temp = CreateMatrix(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = N[n - i - 1][j];
    return temp;
};

bool** TransLeftRight(bool** N, int n)
{
    bool** temp = CreateMatrix(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = N[i][n - 1 - j];
    return temp;
};
void GetData(bool** N, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(getchar() == '@')
                N[i][j] = true;
            else
                N[i][j] = false;
        };
        getchar();
        getchar();
    };
};

bool IsSame(bool** A, bool** B, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(A[i][j] != B[i][j])
                return false;
    return true;
};


