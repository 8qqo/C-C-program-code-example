#include <iostream>
#include <iomanip> // �Ω󱱨��X�榡
using namespace std;

double calculateSummerBill(int usage) {
    double bill = 0.0;
    if (usage > 700) {
        bill += (usage - 700) * 5.63;
        usage = 700;
    }
    if (usage > 500) {
        bill += (usage - 500) * 4.97;
        usage = 500;
    }
    if (usage > 330) {
        bill += (usage - 330) * 4.39;
        usage = 330;
    }
    if (usage > 120) {
        bill += (usage - 120) * 3.02;
        usage = 120;
    }
    bill += usage * 2.10;
    return bill;
}

double calculateNonSummerBill(int usage) {
    double bill = 0.0;
    if (usage > 700) {
        bill += (usage - 700) * 4.50;
        usage = 700;
    }
    if (usage > 500) {
        bill += (usage - 500) * 4.01;
        usage = 500;
    }
    if (usage > 330) {
        bill += (usage - 330) * 3.61;
        usage = 330;
    }
    if (usage > 120) {
        bill += (usage - 120) * 2.68;
        usage = 120;
    }
    bill += usage * 2.10;
    return bill;
}

int main() {
    int usage;
    cout << "�п�J�ϥΫ׼�: ";
    cin >> usage;

    double summerBill = calculateSummerBill(usage);
    double nonSummerBill = calculateNonSummerBill(usage);

    cout << fixed << setprecision(2);
    cout << "�L��q�O: " << summerBill << " ��" << endl;
    cout << "�D�L��q�O: " << nonSummerBill << " ��" << endl;

    return 0;
}

