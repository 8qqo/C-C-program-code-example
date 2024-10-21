#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y;
    const int radius = 100;

    cout << "請輸入點的 x 座標: ";
    cin >> x;
    cout << "請輸入點的 y 座標: ";
    cin >> y;

    // 計算點 (x, y) 與圓心 (0, 0) 之間的距離平方
    int distanceSquared = x * x + y * y;
    int radiusSquared = radius * radius;

    // 判斷是否在圓內或在圓上
    if (distanceSquared <= radiusSquared) {
        cout << "inside" << endl;
    } else {
        cout << "outside" << endl;
    }

    return 0;
}

