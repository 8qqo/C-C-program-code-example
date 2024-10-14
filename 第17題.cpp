#include <iostream>
#include <string>
#include <cstdlib> //  abs ㄧ计

using namespace std;

int main() {
    string digits;
    cout << "叫块计ぇ﹃: ";
    cin >> digits;

    int A = 0; // 计计羆
    int B = 0; // 案计计羆

    for (int i = 0; i < digits.length(); ++i) {
        int num = digits[i] - '0'; // 盢才锣传计
        if ((i + 1) % 2 == 1) {
            // 计计
            A += num;
        } else {
            // 案计计
            B += num;
        }
    }

    int result = abs(A - B);

    // 耞挡狦琌 11 计
    if (result % 11 == 0) {
        cout << digits << "  11 计" << endl;
    } else {
        cout << digits << " ぃ琌 11 计" << endl;
    }

    return 0;
}

