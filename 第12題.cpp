#include <iostream>
#include <iomanip> // �]�t���Y���H�ϥ� setw �M setfill

using namespace std;

int main() {
    int number;
    int originalNumber, encryptedNumber;
    int digit1, digit2, digit3, digit4;
    int temp;

    // Ū���|��Ʀr
    cout << "�п�J�@�ե|��Ʀr: ";
    cin >> number;

    // ��l�Ʀr�s�x�A�Ω����洫�ާ@
    originalNumber = number;

    // �[�K�C�Ӧ�ƨöi��洫
    // ���X�C�Ӧ��
    digit1 = number / 1000;
    number %= 1000;
    digit2 = number / 100;
    number %= 100;
    digit3 = number / 10;
    digit4 = number % 10;

    // �[�K�ާ@
    digit1 = (digit1 + 7) % 10;
    digit2 = (digit2 + 7) % 10;
    digit3 = (digit3 + 7) % 10;
    digit4 = (digit4 + 7) % 10;

    // �洫�ާ@
    // �Ĥ@�Ӧ�ƩM�ĤT�Ӧ�ƥ洫
    temp = digit1;
    digit1 = digit3;
    digit3 = temp;

    // �ĤG�Ӧ�ƩM�ĥ|�Ӧ�ƥ洫
    temp = digit2;
    digit2 = digit4;
    digit4 = temp;

    // �c�إ[�K�᪺�Ʀr
    encryptedNumber = digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;

    // ��X�[�K�᪺���G�A�T�O�|��ƪ��榡�]�]�A�i�઺�e�ɹs�^
    cout << "�[�K�᪺���G��: " << setw(4) << setfill('0') << encryptedNumber << endl;

    return 0;
}

