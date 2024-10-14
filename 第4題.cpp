#include <iostream>
#include <sstream> // 用於字串分割
using namespace std;

bool isTriangle(int a, int b, int c) {
    // 判斷三個邊是否能構成三角形
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    string input;
    cout << "請輸入三個邊長 (以空白隔開): ";
    getline(cin, input); // 讀取整行輸入

    stringstream ss(input); // 將輸入字串轉換為 stringstream
    int a, b, c;
    ss >> a >> b >> c; // 從 stringstream 中提取三個整數

    if (isTriangle(a, b, c)) {
        cout << "fit" << endl;
    } else {
        cout << "unfit" << endl;
    }

    return 0;
}

