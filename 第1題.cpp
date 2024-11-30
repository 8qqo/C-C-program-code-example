#include <iostream>
using namespace std;

bool isPrime(int n) {
    // 璽计0 ㎝ 1 ぃ琌借计
    if (n <= 1) {
        return false;
    }
    
    // 2 ㎝ 3 琌借计
    if (n <= 3) {
        return true;
    }
    
    // 逼埃案计㎝ 3 计
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    
    //  6k ∮ 1 よΑ浪琩计
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int number;
    cout << "叫块俱计: ";
    cin >> number;
    
    if (isPrime(number)) {
        cout << number << "YES" << endl;
    } else {
        cout << number << " NO" << endl;
    }
    
    return 0;
}

