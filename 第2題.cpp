#include <iostream>
#include <iomanip> // �Ω󱱨��X�榡
using namespace std;

int main() {
    double height;
    int gender;
    
    // ��J�����M�ʧO
    cout << "�п�J����(����)�M�ʧO(1�N��k��; 2�N��k��): ";
    cin >> height >> gender;
    
    // �p��з��魫
    double standardWeight;
    if (gender == 1) {
        standardWeight = (height - 80) * 0.7;
    } else if (gender == 2) {
        standardWeight = (height - 70) * 0.6;
    } else {
        cout << "�ʧO��J���~�A�п�J1�N��k�ʩ�2�N��k�ʡC" << endl;
        return 1; // �����{���ê�^���~�N�X
    }
    
    // �]�m��X�榡�A�O�d�@��p��
    cout << fixed << setprecision(1);
    
    // ��X�з��魫
    cout << "�з��魫�O: " << standardWeight << " ����" << endl;
    
    return 0;
}

