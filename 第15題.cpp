#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// �p����I�������Z��������
int calculateDistanceSquare(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    return dx * dx + dy * dy;
}

int main() {
    int N;
    cin >> N;

    vector<int> coordinates(2 * N); // �ΨӦs�x�Ҧ��I���y��

    // Ū���Ҧ��I���y��
    for (int i = 0; i < 2 * N; ++i) {
        cin >> coordinates[i];
    }

    // ��l�̤j�Z�������謰 0
    int maxDistanceSquare = 0;

    // ��X�̻����I���Z��������
    for (int i = 0; i < 2 * N; i += 2) {
        for (int j = i + 2; j < 2 * N; j += 2) {
            int distSq = calculateDistanceSquare(coordinates[i], coordinates[i + 1],
                                                 coordinates[j], coordinates[j + 1]);
            if (distSq > maxDistanceSquare) {
                maxDistanceSquare = distSq;
            }
        }
    }

    // ��X���G
    cout << maxDistanceSquare << endl;

    return 0;
}

