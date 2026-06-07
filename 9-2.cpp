#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// 팰린드롬 검사 함수
bool isPalindrome(int n) {
    string str = to_string(n);
    string rev_str = str;
    reverse(rev_str.begin(), rev_str.end());
    return str == rev_str;
}

// 소수 검사 함수
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    while (true) {
        // 팰린드롬을 먼저 검사해야 시간 초과를 피함
        if (isPalindrome(N) && isPrime(N)) {
            cout << N << "\n";
            break;
        }
        N++;
    }
    return 0;
}