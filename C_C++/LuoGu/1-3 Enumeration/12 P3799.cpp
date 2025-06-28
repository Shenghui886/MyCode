#include <iostream>
#include <limits.h>
using namespace std;

const int MOD = 1000000007;

int main(int argc, char *argv[]) {

    int n;
    cin >> n;
    int arr[5001]{0}, max = INT_MIN, min = INT_MAX;
    long ans = 0;
    for(int _ = 0; _ < n; _++) {
        int __;
        cin >> __;
        if(__>max) max=__;
        if(__<min) min=__;
        arr[__]++;
    }
    for(int i = min; i <=max/2; i++) {
        if(arr[i] == 0) continue;
        for(int j = i; j < max + 1 - i; j++) {
            if(arr[i + j] >= 2) {
                if(i!=j) ans += arr[i] * arr[j] * (arr[i + j] * (arr[i + j] - 1) / 2);
                else ans += (arr[i] * (arr[i] - 1) / 2) * (arr[i + j] * (arr[i + j] - 1) / 2);
                if (ans > MOD) ans -= MOD;
            }
        }
    }
    cout << ans;


    return 0;
}