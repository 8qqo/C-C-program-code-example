#include <iostream>
using namespace std;

// �w�q�@�Ө�ƨӸѱK��ӼƦr
int decryptDigit(int y) {
    // ���թҦ�0��9���Ʀr�A���@�ӼƦr�ϱo (d * 3) % 10 == y
    for (int d = 0; d < 10; ++d) {
        if ((d * 3) % 10 == y) {
            return d;
        }
    }
    return -1; // �z�פW���|��o�@�B
}

int main() {
    int y;
    cout << "�п�J�[�K�᪺�K�X (�|���): ";
    cin >> y;

    int y1 = (y / 1000) % 10;
    int y2 = (y / 100) % 10;
    int y3 = (y / 10) % 10;
    int y4 = y % 10;

    int x1 = decryptDigit(y1);
    int x2 = decryptDigit(y2);
    int x3 = decryptDigit(y3);
    int x4 = decryptDigit(y4);

    int x = x1 * 1000 + x2 * 100 + x3 * 10 + x4;

    cout << "�٭�᪺�K�X�O: " << x << endl;

    return 0;
}

