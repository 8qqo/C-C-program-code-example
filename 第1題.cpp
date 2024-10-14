#include <iostream>
using namespace std;

bool isPrime(int n) {
    // �t�ơB0 �M 1 ���O���
    if (n <= 1) {
        return false;
    }
    
    // 2 �M 3 �O���
    if (n <= 3) {
        return true;
    }
    
    // �ư����ƩM 3 ������
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    
    // �H 6k �� 1 ���覡�ˬd�i�઺�]��
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int number;
    cout << "�п�J�@�Ӿ��: ";
    cin >> number;
    
    if (isPrime(number)) {
        cout << number << "YES" << endl;
    } else {
        cout << number << " NO" << endl;
    }
    
    return 0;
}

