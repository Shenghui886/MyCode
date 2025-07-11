#include <iostream>
using namespace std;

const int MOD = 10000;

int main(int argc, char *argv[]) {

	int n;
	cin >> n;
	if(n == 1) {
		cout << "1" << endl;
		return 0;
	}
	int prepre_all = 1, pre_all = 1, all = 2;
	int pre_L = 0, L = 2;
	for(int i = 2; i < n; i++) {
		prepre_all = pre_all;
		pre_all = all;
		pre_L = L;
		all = (pre_all + prepre_all + pre_L) % MOD;
		L = (prepre_all * 2 + pre_L) % MOD;
	}
	cout << all << endl;

	return 0;
}