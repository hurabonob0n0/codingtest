#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string postfix;
    cin >> postfix; // 후위 표기식 입력

    stack<string> st;

    // 문자열을 처음부터 끝까지 하나씩 확인
    for (char c : postfix) {
        // 1. 피연산자 (소문자 알파벳)인 경우
        if (c >= 'a' && c <= 'z') {
            // char를 string으로 변환하여 스택에 삽입
            st.push(string(1, c));
        }
        // 2. 연산자 ('+' 또는 '-')인 경우
        else {
            // 스택에서 두 개의 수식을 꺼냄
            // 먼저 꺼낸 것이 우측 피연산자(E2), 나중에 꺼낸 것이 좌측 피연산자(E1)
            string E2 = st.top();
            st.pop();

            string E1 = st.top();
            st.pop();

            // 괄호로 묶어 원래의 형태 (E1 연산자 E2) 로 복원
            string new_expr = "(" + E1 + c + E2 + ")";

            // 만들어진 새 수식을 다시 스택에 삽입
            st.push(new_expr);
        }
    }

    // 모든 과정이 끝나면 스택의 맨 위(Top)에 완전한 수식이 남음
    cout << st.top() << "\n";

    return 0;
}