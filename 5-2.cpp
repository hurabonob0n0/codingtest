#include <iostream>

using namespace std;

int main() {
    // 입출력 속도 향상 (C++ 환경 필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        long long A, B, C;
        char op, eq; // 연산자(+, -, *, /)와 등호(=)를 받을 문자형 변수

        // 공백을 기준으로 순서대로 입력받기
        cin >> A >> op >> B >> eq >> C;

        bool isCorrect = false;

        // 연산자에 따른 계산 및 검증
        switch (op) {
        case '+':
            isCorrect = (A + B == C);
            break;
        case '-':
            isCorrect = (A - B == C);
            break;
        case '*':
            isCorrect = (A * B == C);
            break;
        case '/':
            // 나눗셈은 항상 나누어떨어진다고 문제에 명시되어 있으므로 바로 비교
            isCorrect = (A / B == C);
            break;
        }

        // 결과 출력
        if (isCorrect) {
            cout << "correct\n";
        }
        else {
            cout << "wrong answer\n";
        }
    }

    return 0;
}