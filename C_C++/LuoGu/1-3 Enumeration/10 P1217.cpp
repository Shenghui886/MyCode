// 回文质数

#include <iostream>
#include <vector>
using namespace std;

// 欧拉筛
vector<int> EuLerSieve(int n) {
    vector<int> primes;
    if(n < 2) return primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) primes.push_back(i);
        for(int j = 0; j < primes.size(); j++) {
            int next = primes[j] * i;
            if(next > n) break;
            isPrime[next] = false;
            if(i % primes[j] == 0) break; // 确保每个数只被最小质因数标记
        }
    }
    return primes;
}

inline bool isHuiwen(int x) {
    // 处理特殊情况：
    // 1. 负数不是回文数
    // 2. 末尾为0的非零数不是回文数（如10、100）
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int revertedNumber = 0;
    // 当原数字大于反转后的数字时，继续反转后半部分
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    // 偶数位数：直接比较反转后的数字（如1221 → x=12，revertedNumber=12）
    // 奇数位数：忽略中间位比较（如12321 → x=12，revertedNumber=123 → 12 == 123/10）
    return x == revertedNumber || x == revertedNumber / 10;
}

int main(int argc, char *argv[]) {

    int a, b;
    cin >> a >> b;
    vector<int> primes = EuLerSieve(b);
    for(auto const &p : primes)
        if(p >= a && isHuiwen(p)) cout << p << endl;

    return 0;
}