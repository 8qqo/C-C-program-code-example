#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y;
    const int radius = 100;

    cout << "�п�J�I�� x �y��: ";
    cin >> x;
    cout << "�п�J�I�� y �y��: ";
    cin >> y;

    // �p���I (x, y) �P��� (0, 0) �������Z������
    int distanceSquared = x * x + y * y;
    int radiusSquared = radius * radius;

    // �P�_�O�_�b�ꤺ�Φb��W
    if (distanceSquared <= radiusSquared) {
        cout << "inside" << endl;
    } else {
        cout << "outside" << endl;
    }

    return 0;
}

