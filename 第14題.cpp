#include <iostream>
#include <vector>

using namespace std;

// ��ƭ쫬�A��X�p�� N ���Ҧ��ŦX�˳U�W�h���Ʀr
vector<int> findEggNumbers(int N) {
    vector<int> results;

    for (int i = 1; i < N; ++i) {
        if (i % 7 == 2 && i % 9 == 2 && i % 3 == 2) {
            results.push_back(i);
        }
    }

    return results;
}

int main() {
    int N;

    cout << "�п�J N ����: ";
    cin >> N;

    vector<int> validNumbers = findEggNumbers(N);

    cout << "�p�� " << N << " ���Ҧ��ŦX�˳U�W�h���Ʀr��:" << endl;
    for (size_t i = 0; i < validNumbers.size(); ++i) {
        cout << validNumbers[i] << " ";
    }
    cout << endl;

    return 0;
}

