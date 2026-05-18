#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 최대 점수와 최소 점수를 저장할 배열 (크기 3으로 고정하여 메모리 절약)
    int max_dp[3] = { 0, };
    int min_dp[3] = { 0, };

    // 입력을 임시로 받을 변수
    int input[3];

    for (int i = 0; i < n; i++) {
        cin >> input[0] >> input[1] >> input[2];

        // 첫 번째 줄은 그대로 초기값으로 설정
        if (i == 0) {
            max_dp[0] = min_dp[0] = input[0];
            max_dp[1] = min_dp[1] = input[1];
            max_dp[2] = min_dp[2] = input[2];
            continue;
        }

        // --- 최대 점수 계산 ---
        // 배열의 값을 갱신하기 전에 이전 값을 임시로 복사해 둠
        int prev_max_0 = max_dp[0];
        int prev_max_1 = max_dp[1];
        int prev_max_2 = max_dp[2];

        max_dp[0] = max(prev_max_0, prev_max_1) + input[0];
        max_dp[1] = max({ prev_max_0, prev_max_1, prev_max_2 }) + input[1];
        max_dp[2] = max(prev_max_1, prev_max_2) + input[2];

        // --- 최소 점수 계산 ---
        int prev_min_0 = min_dp[0];
        int prev_min_1 = min_dp[1];
        int prev_min_2 = min_dp[2];

        min_dp[0] = min(prev_min_0, prev_min_1) + input[0];
        min_dp[1] = min({ prev_min_0, prev_min_1, prev_min_2 }) + input[1];
        min_dp[2] = min(prev_min_1, prev_min_2) + input[2];
    }

    // 마지막 줄까지 계산된 값 중 최댓값과 최솟값을 찾음
    int final_max = max({ max_dp[0], max_dp[1], max_dp[2] });
    int final_min = min({ min_dp[0], min_dp[1], min_dp[2] });

    cout << final_max << " " << final_min << "\n";

    return 0;
}