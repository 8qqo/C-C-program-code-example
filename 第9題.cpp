#include <iostream>

using namespace std;

int main() {
    int arr1[6], arr2[6];
    
    // 讓使用者輸入 arr1 的值
    cout << "請輸入 arr1 的六個整數值:\n";
    for (int i = 0; i < 6; ++i) {
        cout << "arr1[" << i << "] = ";
        cin >> arr1[i];
    }
    
    // 讓使用者輸入 arr2 的值
    cout << "請輸入 arr2 的六個整數值:\n";
    for (int i = 0; i < 6; ++i) {
        cout << "arr2[" << i << "] = ";
        cin >> arr2[i];
    }
    
    // 計算 arr1 和 arr2 對應位置的元素相加後判斷奇偶
    for (int i = 0; i < 6; ++i) {
        int sum = arr1[i] + arr2[i];
        if (sum % 2 == 0) {
            cout << "0 "; // 偶數
        } else {
            cout << "1 "; // 奇數
        }
    }
    cout << endl;
    
    return 0;
}

