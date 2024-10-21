#include <iostream>
#include <string>

using namespace std;

// 函數原型，用來判斷星座
string findZodiacSign(int month, int day);

int main() {
    int month, day;

    cout << "請輸入月份 (1-12): ";
    cin >> month;
    cout << "請輸入日期 (1-31): ";
    cin >> day;

    // 呼叫函數找到對應的星座
    string zodiacSign = findZodiacSign(month, day);

    // 輸出結果
    cout << "根據您輸入的日期，對應的星座是: " << zodiacSign << endl;

    return 0;
}

// 函數定義，根據月份和日期找到對應的星座名稱（英文）
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

