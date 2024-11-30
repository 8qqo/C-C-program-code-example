#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

double variance(const std::vector<int>& nums) {
    double sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    double mean = sum / nums.size();

    double sq_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sq_sum += (nums[i] - mean) * (nums[i] - mean);
    }
    return sq_sum / nums.size();
}

int main() {
    std::vector<int> nums;
    int N;
    std::cout << "�п�J N ���� (1 <= N <= 30): ";
    std::cin >> N;

    std::cout << "�п�J " << N << " �Ӿ�ơA�åH�ťզr���j�}: ";
    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }

    double var = variance(nums);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "�� " << N << " �Ӿ�ƪ��ܲ��Ƭ�: " << var << std::endl;

    return 0;
}

