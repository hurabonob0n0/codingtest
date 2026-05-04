#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 프로그래머스 제출용 함수
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        // 1. 두 배열의 같은 인덱스 값을 비트 OR 연산
        int combined = arr1[i] | arr2[i];
        string row = "";

        // 2. n개의 비트를 가장 큰 자릿수부터 하나씩 확인 (비트 마스킹)
        for (int j = n - 1; j >= 0; j--) {
            // combined의 j번째 비트가 1인지 확인
            if (combined & (1 << j)) {
                row += "#"; // 1이면 벽
            }
            else {
                row += " "; // 0이면 공백
            }
        }
        // 완성된 한 줄을 정답 배열에 추가
        answer.push_back(row);
    }

    return answer;
}

// Visual Studio 테스트용 main 함수
int main() {
    // 예제 1 테스트
    int n = 5;
    vector<int> arr1 = { 9, 20, 28, 18, 11 };
    vector<int> arr2 = { 30, 1, 21, 17, 28 };

    vector<string> result = solution(n, arr1, arr2);

    cout << "--- 결과 출력 ---\n";
    for (const string& s : result) {
        cout << "\"" << s << "\"\n";
    }

    return 0;
}