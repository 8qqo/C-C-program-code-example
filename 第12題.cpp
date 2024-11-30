#include <iostream>
#include <iomanip> // 繷ゅンㄏノ setw ㎝ setfill

using namespace std;

int main() {
    int number;
    int originalNumber, encryptedNumber;
    int digit1, digit2, digit3, digit4;
    int temp;

    // 弄计
    cout << "叫块舱计: ";
    cin >> number;

    // ﹍计纗ノ尿ユ传巨
    originalNumber = number;

    // 盞–计秈︽ユ传
    // –计
    digit1 = number / 1000;
    number %= 1000;
    digit2 = number / 100;
    number %= 100;
    digit3 = number / 10;
    digit4 = number % 10;

    // 盞巨
    digit1 = (digit1 + 7) % 10;
    digit2 = (digit2 + 7) % 10;
    digit3 = (digit3 + 7) % 10;
    digit4 = (digit4 + 7) % 10;

    // ユ传巨
    // 材计㎝材计ユ传
    temp = digit1;
    digit1 = digit3;
    digit3 = temp;

    // 材计㎝材计ユ传
    temp = digit2;
    digit2 = digit4;
    digit4 = temp;

    // 篶盞计
    encryptedNumber = digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;

    // 块盞挡狦絋玂计Α珹玡旧箂
    cout << "盞挡狦: " << setw(4) << setfill('0') << encryptedNumber << endl;

    return 0;
}

