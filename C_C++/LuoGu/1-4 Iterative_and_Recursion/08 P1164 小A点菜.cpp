#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> dp(M + 1, 0);
    dp[0] = 1; // 初始化：花费0元的方案数为1

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        // 倒序更新dp数组，确保每种菜只被使用一次
        for (int j = M; j >= a; --j) {
            dp[j] += dp[j - a];
        }
    }

    cout << dp[M] << endl;
    return 0;
}