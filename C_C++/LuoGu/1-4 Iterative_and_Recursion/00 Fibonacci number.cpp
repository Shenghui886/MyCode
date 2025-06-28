#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 定义2x2矩阵结构体
struct Matrix {
    long long a, b, c, d;
    Matrix(long long a0, long long b0, long long c0, long long d0) 
        : a(a0), b(b0), c(c0), d(d0) {}
};

// 矩阵乘法
Matrix multiply(const Matrix& m1, const Matrix& m2) {
    return Matrix(
        m1.a * m2.a + m1.b * m2.c,
        m1.a * m2.b + m1.b * m2.d,
        m1.c * m2.a + m1.d * m2.c,
        m1.c * m2.b + m1.d * m2.d
    );
}

// 矩阵快速幂
Matrix matrixPower(Matrix base, long long n) {
    Matrix result(1, 0, 0, 1); // 单位矩阵
    while (n > 0) {
        if (n & 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        n >>= 1;
    }
    return result;
}

// 计算斐波那契数
long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // 基础矩阵: [ [1,1], [1,0] ]
    Matrix base(1, 1, 1, 0);
    Matrix result = matrixPower(base, n - 1);
    return result.a; // 返回结果矩阵左上角元素
}

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

// 使用高精度整数计算斐波那契数
string fibonacciBigInt(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    
    string a = "0";
    string b = "1";
    string c;
    
    for (int i = 2; i <= n; i++) {
        c = addBigInt(a, b);
        a = b;
        b = c;
    }
    
    return c;
}

int main() {
    int n;
    cin >> n;
    n++;
    
    if (n <= 92) {
        // 使用快速矩阵幂计算（最多到92位）
        // 这里省略矩阵幂实现，保留原始实现
        cout << fibonacci(n) << endl;
    } else {
        // 使用高精度计算
        cout << fibonacciBigInt(n) << endl;
    }
    
    return 0;
}