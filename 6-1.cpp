#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 프로그래머스 제출용 solution 함수
int solution(vector<vector<int>> triangle) {
    // 삼각형의 높이 (줄의 개수)
    int n = triangle.size();

    // 맨 아래층의 바로 위층(n-2)부터 꼭대기(0)까지 거꾸로 훑고 올라갑니다.
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            // 현재 칸(i, j)에서 내려갈 수 있는 바로 아래층의 두 칸 중 큰 값을 현재 칸에 누적합니다.
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    // 꼭대기 층에 모든 경로의 최댓값이 누적되어 모이게 됩니다.
    return triangle[0][0];
}

// 로컬 테스트용 main 함수
int main() {
    // 문제에 주어진 예제 테스트 케이스
    vector<vector<int>> triangle = {
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5}
    };

    // solution 함수 호출 및 결과 저장
    int result = solution(triangle);

    // 결과 출력 (정답: 30)
    cout << "삼각형을 거쳐가는 경로의 최댓값: " << result << "\n";

    return 0;
}