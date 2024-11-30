#include <iostream>
#include <cmath>
#include <iomanip> // �Ω󱱨��X�榡

using namespace std;

// �p����I�������Z��������
double distanceSquare(int x1, int y1, int x2, int y2) {
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

// �p�⤤���u���ײv
double perpendicularSlope(int x1, int y1, int x2, int y2) {
    // ���I�y��
    double mx = (x1 + x2) / 2.0;
    double my = (y1 + y2) / 2.0;

    // ��u�q���ײv
    double slope = static_cast<double>(y2 - y1) / (x2 - x1);

    // ���������u���ײv
    return -1.0 / slope;
}

// �p���߮y�ЩM�b�|
void calculateCircle(int x1, int y1, int x2, int y2, int x3, int y3,
                     double& rx, double& ry, double& radius) {
    // AB �����u���ײv
    double slope1 = perpendicularSlope(x1, y1, x2, y2);
    // BC �����u���ײv
    double slope2 = perpendicularSlope(x2, y2, x3, y3);

    // AB ���I�y��
    double mx1 = (x1 + x2) / 2.0;
    double my1 = (y1 + y2) / 2.0;
    // BC ���I�y��
    double mx2 = (x2 + x3) / 2.0;
    double my2 = (y2 + y3) / 2.0;

    // �Ѥ�{�o���߮y��
    rx = ((my2 - my1) + slope1 * mx1 - slope2 * mx2) / (slope1 - slope2);
    ry = my1 + slope1 * (rx - mx1);

    // �p��b�|
    radius = sqrt(distanceSquare(x1, y1, rx, ry));
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double rx, ry, radius;
    calculateCircle(x1, y1, x2, y2, x3, y3, rx, ry, radius);

    // �榡�ƿ�X���G�A�O�d�T��p��
    cout << fixed << setprecision(3) << rx << " " << ry << " " << radius << endl;

    return 0;
}

