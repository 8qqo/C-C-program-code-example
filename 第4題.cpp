#include <iostream>
#include <sstream> // �Ω�r�����
using namespace std;

bool isTriangle(int a, int b, int c) {
    // �P�_�T����O�_��c���T����
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    string input;
    cout << "�п�J�T����� (�H�ťչj�}): ";
    getline(cin, input); // Ū������J

    stringstream ss(input); // �N��J�r���ഫ�� stringstream
    int a, b, c;
    ss >> a >> b >> c; // �q stringstream �������T�Ӿ��

    if (isTriangle(a, b, c)) {
        cout << "fit" << endl;
    } else {
        cout << "unfit" << endl;
    }

    return 0;
}

