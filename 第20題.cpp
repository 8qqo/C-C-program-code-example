#include <iostream>
#include <string>

int main() {
    int city_code[] = {
        10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20,
        21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33
    };

    std::string id;
    std::cout << "�п�J�����Ҧr��: ";
    std::cin >> id;

    if (id.length() != 10) {
        std::cout << "�����Ҧr�����׿��~!" << std::endl;
        return 1;
    }

    // ����Ĥ@�Ӧr�������������N�X��
    int city_value = city_code[id[0] - 'A'];
    int sum = (city_value / 10) + (city_value % 10) * 9;

    // �p�Ⱶ�U��8�ӼƦr���[�v��
    for (int i = 1; i <= 8; ++i) {
        sum += (id[i] - '0') * (9 - i);
    }

    // �[�W�̫�@��Ʀr����
    sum += id[9] - '0';

    if (sum % 10 == 0) {
        std::cout << "���T!" << std::endl;
    } else {
        std::cout << "���~!" << std::endl;
    }

    return 0;
}

