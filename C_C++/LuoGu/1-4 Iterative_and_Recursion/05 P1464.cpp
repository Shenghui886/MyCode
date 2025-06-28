// P1464 Function

#include <iostream>
using namespace std;

int main(void) {

    long long arr[20][20][20];
    long long a, b, c;
    for(int j = 0; j < 20; j++)
        for(int i = 0; i < 20; i++)
            arr[0][i][j] = 2;
    for(int j = 0; j < 20; j++)
        for(int i = 0; i < 20; i++)
        {
            if(i == 0)
            {
                arr[i][j][0] = 2;
                arr[i][0][j] = 2;
            }
            else
            {
                if(j == 0)
                {
                    arr[i][j][0] = arr[i - 1][j][0] + 1;
                    arr[i][0][j] = arr[i - 1][0][j] + 1;
                }
                else
                {
                    arr[i][j][0] = arr[i - 1][j][0] + arr[i - 1][j - 1][0];
                    arr[i][0][j] = arr[i - 1][0][j] + arr[i - 1][0][j - 1];
                }
            }
        }
    for(int i = 1; i < 20; i++)
        for(int j = 1; j < 20; j++)
            for(int l = 1; l < 20; l++)
            {
                if(i < j && j < l)
                    arr[i][j][l] = arr[i][j][l - 1] + arr[i][j - 1][l - 1] - arr[i][j - 1][l];
                else
                    arr[i][j][l] = arr[i - 1][j][l] + arr[i - 1][j - 1][l] + arr[i - 1][j][l - 1] - arr[i - 1][j - 1][l - 1];
            }
        
    while(scanf("%lld %lld %lld", &a, &b, &c))
    {
        if(a == -1 && b == -1 && c == -1)
            break;
        if(a < 1 || b < 1 || c < 1)
        {
            printf("w(%lld, %lld, %lld) = %d\n", a, b, c, 1);
            continue;
        }
        if(a > 20 || b > 20 || c > 20)
        {
            printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, arr[19][19][19]);
            continue;
        }
        
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, arr[a - 1][b - 1][c - 1]);

    }

    return 0;
}

