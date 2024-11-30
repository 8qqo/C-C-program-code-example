#include <iostream>
#include <cmath>
#include <iomanip>

// �w�q��ƭp�ⶥ��
double factorial(int n) {
    double fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// �w�q��ƭp�� sin(x) �������
double approximate_sin(double x, int N) {
    double result = 0;
    for(int n = 0; n < N; n++) {
        double term = pow(-1, n) * pow(x, 2*n+1) / factorial(2*n+1);
        result += term;
    }
    return result;
}

int main() {
    // ��J x �M N
    double x;
    int N;
    std::cout << "�п�J x ���ȡ]�|�ס^: ";
    std::cin >> x;
    std::cout << "��J����� N (1 <= N <= 10): ";
    std::cin >> N;

    // �ˬd N �O�_�b�d��
    if (1 <= N && N <= 10) {
        // �p��ÿ�X���G
        double approximation = approximate_sin(x, N);
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "sin(" << x << ") ���e " << N << " ���żƪ���Ȭ�: " << approximation << std::endl;
    } else {
        std::cout << "N ���Ȥ��b���\���d�򤺡C" << std::endl;
    }

    return 0;
}

