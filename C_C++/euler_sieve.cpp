#include<iostream>
#include <utility>
#include <vector>
using namespace std;

//欧拉筛法，时间复杂度位O(n)
pair<vector<int>, vector<bool>> euler_sieve(int n) {
    if (n < 2)
        return make_pair(vector<int>(), vector<bool>(n + 1, false));
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    
    
    is_prime[0] = false;
    is_prime[1] = false;
    
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i])
            primes.push_back(i);

        for (auto p : primes) {
            long long next = (long long)i * p;
            if (next > n) break;
            is_prime[next] = false;
            if (i % p == 0) break;
        }
    }
    return make_pair(primes, is_prime);
}

int main() {
	
	int n = 100;
    auto [primes, is_prime] = euler_sieve(n);
    
    cout << "质数列表: ";
    for (int p : primes) {
        cout << p << " ";
    }
    cout << "\n\n";
    
    // 使用标记数组快速查询
    cout << "质数查询:\n";
    cout << "15 是质数? " << (is_prime[15] ? "是" : "否") << endl;
    cout << "17 是质数? " << (is_prime[17] ? "是" : "否") << endl;
    cout << "97 是质数? " << (is_prime[97] ? "是" : "否") << endl;
    
    return 0;
}
