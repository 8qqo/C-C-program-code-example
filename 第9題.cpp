#include <iostream>

using namespace std;

int main() {
    int arr1[6], arr2[6];
    
    // ���ϥΪ̿�J arr1 ����
    cout << "�п�J arr1 �����Ӿ�ƭ�:\n";
    for (int i = 0; i < 6; ++i) {
        cout << "arr1[" << i << "] = ";
        cin >> arr1[i];
    }
    
    // ���ϥΪ̿�J arr2 ����
    cout << "�п�J arr2 �����Ӿ�ƭ�:\n";
    for (int i = 0; i < 6; ++i) {
        cout << "arr2[" << i << "] = ";
        cin >> arr2[i];
    }
    
    // �p�� arr1 �M arr2 ������m�������ۥ[��P�_�_��
    for (int i = 0; i < 6; ++i) {
        int sum = arr1[i] + arr2[i];
        if (sum % 2 == 0) {
            cout << "0 "; // ����
        } else {
            cout << "1 "; // �_��
        }
    }
    cout << endl;
    
    return 0;
}

