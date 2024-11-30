#include <iostream>
#include <string>

int main() {
    int city_code[] = {
        10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20,
        21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33
    };

    std::string id;
    std::cout << "請輸入身分證字號: ";
    std::cin >> id;

    if (id.length() != 10) {
        std::cout << "身分證字號長度錯誤!" << std::endl;
        return 1;
    }

    // 獲取第一個字母對應的城市代碼值
    int city_value = city_code[id[0] - 'A'];
    int sum = (city_value / 10) + (city_value % 10) * 9;

    // 計算接下來8個數字的加權值
    for (int i = 1; i <= 8; ++i) {
        sum += (id[i] - '0') * (9 - i);
    }

    // 加上最後一位數字的值
    sum += id[9] - '0';

    if (sum % 10 == 0) {
        std::cout << "正確!" << std::endl;
    } else {
        std::cout << "錯誤!" << std::endl;
    }

    return 0;
}

