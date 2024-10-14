#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 計算兩點之間的距離的平方
int calculateDistanceSquare(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    return dx * dx + dy * dy;
}

int main() {
    int N;
    cin >> N;

    vector<int> coordinates(2 * N); // 用來存儲所有點的座標

    // 讀取所有點的座標
    for (int i = 0; i < 2 * N; ++i) {
        cin >> coordinates[i];
    }

    // 初始最大距離的平方為 0
    int maxDistanceSquare = 0;

    // 找出最遠兩點的距離的平方
    for (int i = 0; i < 2 * N; i += 2) {
        for (int j = i + 2; j < 2 * N; j += 2) {
            int distSq = calculateDistanceSquare(coordinates[i], coordinates[i + 1],
                                                 coordinates[j], coordinates[j + 1]);
            if (distSq > maxDistanceSquare) {
                maxDistanceSquare = distSq;
            }
        }
    }

    // 輸出結果
    cout << maxDistanceSquare << endl;

    return 0;
}

