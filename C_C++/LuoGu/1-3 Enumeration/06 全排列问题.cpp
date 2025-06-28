#include <iostream>
using namespace std;

int arr[9];
void dfs(int k, int n)
{
    if(k > n)
    {
        for(int i = 0; i < n; i++)
            printf("%5d", arr[i]);
        putchar('\n');
        return;
    }
    for(int i = 0; i < n; i++)
    {
        int j = 0;
        for(; j < k - 1; j++)
            if(i + 1 == arr[j])
                break;
        if(j == k - 1)
        {
            arr[k - 1] = i + 1;
            dfs(k + 1, n);
        }
    }
}

int main(void) {

    int n;
    cin >> n;
    dfs(1, n);

    return 0;
}
