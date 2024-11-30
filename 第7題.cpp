#include <iostream>

using namespace std;

// �p�ⶥ�������
unsigned long long factorial(int num) {
    unsigned long long result = 1;
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    return result;
}

// �p��զX�ƪ����
unsigned long long combination(int m, int n) {
    if (n > m) return 0;
    return factorial(m) / (factorial(n) * factorial(m - n));
}

int main() {
    int m, n;
    cout << "�п�J��� m: ";
    cin >> m;
    cout << "�п�J��� n: ";
    cin >> n;

    // �p�� C(m, n)
    unsigned long long result = combination(m, n);

    cout << "C(" << m << ", " << n << ") = " << result << endl;

    return 0;
}

