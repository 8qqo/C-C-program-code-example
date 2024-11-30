#include <iostream>
#include <vector>

using namespace std;

// ㄧ计т N ┮Τ才杆砋砏玥计
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

    cout << "叫块 N : ";
    cin >> N;

    vector<int> validNumbers = findEggNumbers(N);

    cout << " " << N << " ┮Τ才杆砋砏玥计Τ:" << endl;
    for (size_t i = 0; i < validNumbers.size(); ++i) {
        cout << validNumbers[i] << " ";
    }
    cout << endl;

    return 0;
}

