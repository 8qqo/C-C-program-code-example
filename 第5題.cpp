#include <iostream>
using namespace std;

// 定義一個函數來解密單個數字
int decryptDigit(int y) {
    // 嘗試所有0到9的數字，找到一個數字使得 (d * 3) % 10 == y
    for (int d = 0; d < 10; ++d) {
        if ((d * 3) % 10 == y) {
            return d;
        }
    }
    return -1; // 理論上不會到這一步
}

int main() {
    int y;
    cout << "請輸入加密後的密碼 (四位數): ";
    cin >> y;

    int y1 = (y / 1000) % 10;
    int y2 = (y / 100) % 10;
    int y3 = (y / 10) % 10;
    int y4 = y % 10;

    int x1 = decryptDigit(y1);
    int x2 = decryptDigit(y2);
    int x3 = decryptDigit(y3);
    int x4 = decryptDigit(y4);

    int x = x1 * 1000 + x2 * 100 + x3 * 10 + x4;

    cout << "還原後的密碼是: " << x << endl;

    return 0;
}

