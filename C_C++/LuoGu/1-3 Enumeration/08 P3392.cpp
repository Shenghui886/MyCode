// 涂国旗

#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char *argv[]) {

    int N, M;
    cin >> N >> M;
    int W[N]{}, B[N]{}, R[N]{};
    for(int i = 0; i < N; i++) {
        W[i] = i?M+W[i-1]:M;
        B[i] = i?M+B[i-1]:M;
        R[i] = i?M+R[i-1]:M;
        for(int j = 0; j < M; j++) {
            char _;
            cin >> _;
            _=='W'?W[i]--:_=='B'?B[i]--:R[i]--;
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < N - 2; i++) 
        for(int j = i + 1; j < N-1; j++) {
            ans = W[i]+B[j]-B[i]+R[N-1]-R[j]<ans?W[i]+B[j]-B[i]+R[N-1]-R[j]:ans;
        }
    cout << ans;

    return 0;
}