#include <iostream>
using namespace std;

const int NUM[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(int argc, char *argv[]) {

    int n, ans = 0;
    cin >> n;
    n -= 4;
    if(n < 9) {
        cout << 0;
        return 0;
    }

    for(int a = 0; a <= 711; a++) {
        for(int b = a; b <= 711; b++) {
            int c;
            c = a +b;
            int _=a,__=b,___=c,____=n;
            if(a == 0) ____ -= 6;
            
            if(b == 0) ____ -= 6;
            if(c == 0) ____ -= 6;
            while(_) {
                ____-=NUM[_%10];
                _/=10;
            }
            while(__) {
                ____-=NUM[__%10];
                __/=10;
            }
            while(___) {
                ____-=NUM[___%10];
                ___/=10;
            }
            if(____==0) {
                if(a == b) ans ++;
                else ans += 2;
            }
        }
    }
    cout << ans;

    return 0;
}