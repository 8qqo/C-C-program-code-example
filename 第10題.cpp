#include <iostream>

using namespace std;

int main() {
    string input;

    cout << "請輸入一串字串（包含英文字母和數字）: ";
    getline(cin, input); // 讀取整行輸入

    // 遍歷輸入的每個字符，進行轉換
    for (int i = 0; i < input.length(); ++i) {
        if (isalpha(input[i])) { // 如果是英文字母
            // 將小寫轉為大寫，不使用轉換函式
            if (input[i] >= 'a' && input[i] <= 'z') {
                input[i] = input[i] - 'a' + 'A';
            }
        } else if (isdigit(input[i])) { // 如果是數字
            // 將數字轉換為 '0'
            input[i] = '0';
        }
    }

    cout << "轉換後的結果為: " << input << endl;

    return 0;
}

