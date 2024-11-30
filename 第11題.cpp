#include <iostream>
#include <string>

using namespace std;

// ��ƭ쫬�A�ΨӧP�_�P�y
string findZodiacSign(int month, int day);

int main() {
    int month, day;

    cout << "�п�J��� (1-12): ";
    cin >> month;
    cout << "�п�J��� (1-31): ";
    cin >> day;

    // �I�s��Ƨ��������P�y
    string zodiacSign = findZodiacSign(month, day);

    // ��X���G
    cout << "�ھڱz��J������A�������P�y�O: " << zodiacSign << endl;

    return 0;
}

// ��Ʃw�q�A�ھڤ���M������������P�y�W�١]�^��^
string findZodiacSign(int month, int day) {
    string zodiacSign;

    if ((month == 1 && day >= 21) || (month == 2 && day <= 18)) {
        zodiacSign = "Aquarius";
    } else if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) {
        zodiacSign = "Pisces";
    } else if ((month == 3 && day >= 21) || (month == 4 && day <= 20)) {
        zodiacSign = "Aries";
    } else if ((month == 4 && day >= 21) || (month == 5 && day <= 21)) {
        zodiacSign = "Taurus";
    } else if ((month == 5 && day >= 22) || (month == 6 && day <= 21)) {
        zodiacSign = "Gemini";
    } else if ((month == 6 && day >= 22) || (month == 7 && day <= 22)) {
        zodiacSign = "Cancer";
    } else if ((month == 7 && day >= 23) || (month == 8 && day <= 23)) {
        zodiacSign = "Leo";
    } else if ((month == 8 && day >= 24) || (month == 9 && day <= 23)) {
        zodiacSign = "Virgo";
    } else if ((month == 9 && day >= 24) || (month == 10 && day <= 23)) {
        zodiacSign = "Libra";
    } else if ((month == 10 && day >= 24) || (month == 11 && day <= 22)) {
        zodiacSign = "Scorpio";
    } else if ((month == 11 && day >= 23) || (month == 12 && day <= 21)) {
        zodiacSign = "Sagittarius";
    } else if ((month == 12 && day >= 22) || (month == 1 && day <= 20)) {
        zodiacSign = "Capricorn";
    } else {
        zodiacSign = "Unknown";
    }

    return zodiacSign;
}

