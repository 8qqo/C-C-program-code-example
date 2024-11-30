#include <iostream>

using namespace std;

int main() {
    int n, m;
    cout << "�п�J�Y���`�� (n): ";
    cin >> n;
    cout << "�п�J�}���`�� (m): ";
    cin >> m;

    // �Ѥ�{�� S + R = n �M 2S + 4R = m ���ɥX:
    // S = (4n - m) / 2
    // R = n - S

    int S = (4 * n - m) / 2;
    int R = n - S;

    // �ˬd S �M R �O�_���D�t���
    if (S >= 0 && R >= 0 && (4 * n - m) % 2 == 0) {
        cout << "�t�ϦѤH���ƶq: " << S << endl;
        cout << "�������ƶq: " << R << endl;
    } else {
        cout << "�L�ѡA�нT�{��J���ƭȬO�_���T�C" << endl;
    }

    return 0;
}

