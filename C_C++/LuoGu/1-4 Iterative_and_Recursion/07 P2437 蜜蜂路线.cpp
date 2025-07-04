#include <iostream>
#include <algorithm>
using namespace std;

// 高精度整数加法
string addBigInt(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    
    reverse(result.begin(), result.end());
    return result;
}

string Fibonacci(int n) {
	string result;
	string num1("1"), num2("2");
	if(n == 1) return string("1");
	else if(n == 2) return string("2");
	else {
		for(int i = 0; i < n - 2; i++) {
			result = addBigInt(num1, num2);
			num1 = num2;
			num2 = result;
		}
	}
	return result;
}

int main(int argc, char *argv[]) {

	int n, m;
	cin >> n >> m;
	cout << Fibonacci(m - n) << endl;

	return 0;
}