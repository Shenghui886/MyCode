#include <iostream>
#include <vector>
#include <utility>
using namespace std;

//欧拉筛法，时间复杂度位O(n)
pair<vector<int>, vector<bool>> euler_sieve(int n) {
    // 初始化标记数组
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    
    // 处理特殊情况
    if (n < 2) {
        return make_pair(primes, is_prime);
    }
    
    // 0和1不是质数
    is_prime[0] = false;
    is_prime[1] = false;
    
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        
        for (size_t j = 0; j < primes.size(); ++j) {
            int p = primes[j];
            long long next = (long long)i * p;
            
            if (next > n) break;
            
            is_prime[next] = false;
            
            // 关键优化：当i能被当前质数整除时停止
            if (i % p == 0) break;
        }
    }
    
    return make_pair(primes, is_prime);
}

int dfs(int sum, int k, int index, const vector<int> &arr, const vector<bool> &is_prime) {
	int ans = 0;
	if (k == 0) {
		if(is_prime[sum]) return 1;
		else return 0;
	}
	k--;
	for(int i = index; i < arr.size() - k; i++) {
		ans += dfs(sum + arr[i], k, i + 1, arr, is_prime);
	}
	return ans;
}

int main(int argc, char *argv[]) {

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(auto &x : arr) {
		cin >> x;
	}
	auto [primes, is_prime] = euler_sieve(k * 5000000);
	cout << dfs(0, k, 0, arr, is_prime) << endl;

	return 0;
}