#include <iostream>

using namespace std;

// 計算階乘的函數
unsigned long long factorial(int num) {
    unsigned long long result = 1;
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    return result;
}

// 計算組合數的函數
unsigned long long combination(int m, int n) {
    if (n > m) return 0;
    return factorial(m) / (factorial(n) * factorial(m - n));
}

int main() {
    int m, n;
    cout << "請輸入整數 m: ";
    cin >> m;
    cout << "請輸入整數 n: ";
    cin >> n;

    // 計算 C(m, n)
    unsigned long long result = combination(m, n);

    cout << "C(" << m << ", " << n << ") = " << result << endl;

    return 0;
}

