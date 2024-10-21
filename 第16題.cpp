#include <iostream>
#include <cmath>
#include <iomanip> // 用於控制輸出格式

using namespace std;

// 計算兩點之間的距離的平方
double distanceSquare(int x1, int y1, int x2, int y2) {
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

// 計算中垂線的斜率
double perpendicularSlope(int x1, int y1, int x2, int y2) {
    // 中點座標
    double mx = (x1 + x2) / 2.0;
    double my = (y1 + y2) / 2.0;

    // 原線段的斜率
    double slope = static_cast<double>(y2 - y1) / (x2 - x1);

    // 垂直平分線的斜率
    return -1.0 / slope;
}

// 計算圓心座標和半徑
void calculateCircle(int x1, int y1, int x2, int y2, int x3, int y3,
                     double& rx, double& ry, double& radius) {
    // AB 中垂線的斜率
    double slope1 = perpendicularSlope(x1, y1, x2, y2);
    // BC 中垂線的斜率
    double slope2 = perpendicularSlope(x2, y2, x3, y3);

    // AB 中點座標
    double mx1 = (x1 + x2) / 2.0;
    double my1 = (y1 + y2) / 2.0;
    // BC 中點座標
    double mx2 = (x2 + x3) / 2.0;
    double my2 = (y2 + y3) / 2.0;

    // 解方程得到圓心座標
    rx = ((my2 - my1) + slope1 * mx1 - slope2 * mx2) / (slope1 - slope2);
    ry = my1 + slope1 * (rx - mx1);

    // 計算半徑
    radius = sqrt(distanceSquare(x1, y1, rx, ry));
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double rx, ry, radius;
    calculateCircle(x1, y1, x2, y2, x3, y3, rx, ry, radius);

    // 格式化輸出結果，保留三位小數
    cout << fixed << setprecision(3) << rx << " " << ry << " " << radius << endl;

    return 0;
}

