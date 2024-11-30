#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

// ��ƭ쫬�A�Ω��� 3x3 �}�C���[�k
void add(int A[][COLS], int B[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// ��ƭ쫬�A�Ω���� 3x3 �}�C
void displayArray(int arr[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int array1[ROWS][COLS];
    int array2[ROWS][COLS];
    int sum[ROWS][COLS];

    // ���ܥΤ��J�Ĥ@�Ӱ}�C�����e
    cout << "�п�J�Ĥ@�� 3x3 �}�C�����e�]�C�Ӥ����ΪŮ���j�^:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cin >> array1[i][j];
        }
    }

    // ���ܥΤ��J�ĤG�Ӱ}�C�����e
    cout << "�п�J�ĤG�� 3x3 �}�C�����e�]�C�Ӥ����ΪŮ���j�^:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cin >> array2[i][j];
        }
    }

    // �I�s add ��ƶi��}�C�[�k
    add(array1, array2, sum);

    // ��X�[�k���G
    cout << "��Ӱ}�C�ۥ[�����G��:" << endl;
    displayArray(sum);

    return 0;
}

