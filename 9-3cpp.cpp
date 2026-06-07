#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// b진수 배열을 10진수로 변환
long long toDecimal(int b, const vector<int>& digits) {
    long long decimal_val = 0;
    long long multiplier = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
        decimal_val += digits[i] * multiplier;
        multiplier *= b;
    }
    return decimal_val;
}

int main() {
    int b, lenA, lenB;
    if (!(cin >> b >> lenA >> lenB)) return 0;

    vector<int> A(lenA), B(lenB);
    for (int i = 0; i < lenA; i++) cin >> A[i];
    for (int i = 0; i < lenB; i++) cin >> B[i];

    // 1. 10진수로 변환 및 곱셈
    long long decA = toDecimal(b, A);
    long long decB = toDecimal(b, B);
    long long result = decA * decB;

    // 2. 결과를 다시 b진수로 변환
    if (result == 0) {
        cout << 1 << "\n" << 0 << "\n";
        return 0;
    }

    vector<int> res_digits;
    while (result > 0) {
        res_digits.push_back(result % b);
        result /= b;
    }
    reverse(res_digits.begin(), res_digits.end());

    // 출력
    cout << res_digits.size() << "\n";
    for (int i = 0; i < res_digits.size(); i++) {
        cout << res_digits[i] << (i == res_digits.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}