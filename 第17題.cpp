#include <iostream>
#include <string>
#include <cstdlib> // �]�t abs ���

using namespace std;

int main() {
    string digits;
    cout << "�п�J�@�ӯ¼Ʀr���r��: ";
    cin >> digits;

    int A = 0; // �_��ƪ��Ʀr�[�`
    int B = 0; // ����ƪ��Ʀr�[�`

    for (int i = 0; i < digits.length(); ++i) {
        int num = digits[i] - '0'; // �N�r���ഫ���Ʀr
        if ((i + 1) % 2 == 1) {
            // �_�Ʀ�Ʀr
            A += num;
        } else {
            // ���Ʀ�Ʀr
            B += num;
        }
    }

    int result = abs(A - B);

    // �P�_���G�O�_�� 11 ������
    if (result % 11 == 0) {
        cout << digits << " �� 11 ������" << endl;
    } else {
        cout << digits << " ���O 11 ������" << endl;
    }

    return 0;
}

