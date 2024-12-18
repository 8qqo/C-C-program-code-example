#include <iostream>
#include <cmath>
#include <iomanip>

// 定義函數計算階乘
double factorial(int n) {
    double fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// 定義函數計算 sin(x) 的近似值
double approximate_sin(double x, int N) {
    double result = 0;
    for(int n = 0; n < N; n++) {
        double term = pow(-1, n) * pow(x, 2*n+1) / factorial(2*n+1);
        result += term;
    }
    return result;
}

int main() {
    // 輸入 x 和 N
    double x;
    int N;
    std::cout << "請輸入 x 的值（徑度）: ";
    std::cin >> x;
    std::cout << "輸入正整數 N (1 <= N <= 10): ";
    std::cin >> N;

    // 檢查 N 是否在範圍內
    if (1 <= N && N <= 10) {
        // 計算並輸出結果
        double approximation = approximate_sin(x, N);
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "sin(" << x << ") 的前 " << N << " 項級數近似值為: " << approximation << std::endl;
    } else {
        std::cout << "N 的值不在允許的範圍內。" << std::endl;
    }

    return 0;
}

