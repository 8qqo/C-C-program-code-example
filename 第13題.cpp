#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

// 函數原型，用於兩個 3x3 陣列的加法
void add(int A[][COLS], int B[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// 函數原型，用於顯示 3x3 陣列
void displayArray(int arr[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int array1[ROWS][COLS];
    int array2[ROWS][COLS];
    int sum[ROWS][COLS];

    // 提示用戶輸入第一個陣列的內容
    cout << "請輸入第一個 3x3 陣列的內容（每個元素用空格分隔）:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cin >> array1[i][j];
        }
    }

    // 提示用戶輸入第二個陣列的內容
    cout << "請輸入第二個 3x3 陣列的內容（每個元素用空格分隔）:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cin >> array2[i][j];
        }
    }

    // 呼叫 add 函數進行陣列加法
    add(array1, array2, sum);

    // 輸出加法結果
    cout << "兩個陣列相加的結果為:" << endl;
    displayArray(sum);

    return 0;
}

