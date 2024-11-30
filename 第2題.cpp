#include <iostream>
#include <iomanip> // 用於控制輸出格式
using namespace std;

int main() {
    double height;
    int gender;
    
    // 輸入身高和性別
    cout << "請輸入身高(公分)和性別(1代表男性; 2代表女性): ";
    cin >> height >> gender;
    
    // 計算標準體重
    double standardWeight;
    if (gender == 1) {
        standardWeight = (height - 80) * 0.7;
    } else if (gender == 2) {
        standardWeight = (height - 70) * 0.6;
    } else {
        cout << "性別輸入錯誤，請輸入1代表男性或2代表女性。" << endl;
        return 1; // 結束程式並返回錯誤代碼
    }
    
    // 設置輸出格式，保留一位小數
    cout << fixed << setprecision(1);
    
    // 輸出標準體重
    cout << "標準體重是: " << standardWeight << " 公斤" << endl;
    
    return 0;
}

