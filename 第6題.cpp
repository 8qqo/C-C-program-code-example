#include <iostream>

using namespace std;

int main() {
    int n, m;
    cout << "請輸入頭的總數 (n): ";
    cin >> n;
    cout << "請輸入腳的總數 (m): ";
    cin >> m;

    // 由方程式 S + R = n 和 2S + 4R = m 推導出:
    // S = (4n - m) / 2
    // R = n - S

    int S = (4 * n - m) / 2;
    int R = n - S;

    // 檢查 S 和 R 是否為非負整數
    if (S >= 0 && R >= 0 && (4 * n - m) % 2 == 0) {
        cout << "聖誕老人的數量: " << S << endl;
        cout << "馴鹿的數量: " << R << endl;
    } else {
        cout << "無解，請確認輸入的數值是否正確。" << endl;
    }

    return 0;
}

