#include <iostream>

using namespace std;

int main() {
    string input;

    cout << "�п�J�@��r��]�]�t�^��r���M�Ʀr�^: ";
    getline(cin, input); // Ū������J

    // �M����J���C�Ӧr�šA�i���ഫ
    for (int i = 0; i < input.length(); ++i) {
        if (isalpha(input[i])) { // �p�G�O�^��r��
            // �N�p�g�ର�j�g�A���ϥ��ഫ�禡
            if (input[i] >= 'a' && input[i] <= 'z') {
                input[i] = input[i] - 'a' + 'A';
            }
        } else if (isdigit(input[i])) { // �p�G�O�Ʀr
            // �N�Ʀr�ഫ�� '0'
            input[i] = '0';
        }
    }

    cout << "�ഫ�᪺���G��: " << input << endl;

    return 0;
}

