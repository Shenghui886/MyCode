#include <iostream>
#include <limits.h>
using namespace std;

int main(int argc, char *argv[]) {

    int n;
    cin >> n;
    long long s[10];
    long long b[10];
    for(int i = 0; i < n; i++)
        cin >> s[i] >> b[i];

    long long ans = LONG_LONG_MAX;
    for(int state = 1; state < (1 << n); state++) {
        long long mul = 1;
        long long sum = 0;
        for(int i = 0; i < n; i++)
            if((1 << i) & state) {
                mul *= s[i];
                sum += b[i];
            }
        ans = min(abs(mul - sum), ans);
    }

    cout << ans;

    return 0;
}