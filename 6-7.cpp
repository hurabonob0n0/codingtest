#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // dp[i]는 정수 i를 1로 만드는데 필요한 최소 연산 횟수
    vector<int> dp(n + 1, 0);

    // 1은 이미 1이므로 연산이 0번 필요함. (dp[1] = 0)
    // 2부터 N까지 바텀업(Bottom-Up) 방식으로 최소 횟수를 구해나감
    for (int i = 2; i <= n; i++) {

        // 1. 우선 1을 빼는 경우의 횟수를 구함
        // 이전 숫자인 (i-1)을 1로 만드는 횟수에 1번(현재 연산)을 더함
        dp[i] = dp[i - 1] + 1;

        // 2. 만약 2로 나누어 떨어진다면?
        // 방금 구한 '1을 뺐을 때의 횟수'와 '2로 나누었을 때의 횟수' 중 더 작은 값을 선택
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        // 3. 만약 3으로 나누어 떨어진다면?
        // 현재까지 저장된 최소 횟수와 '3으로 나누었을 때의 횟수' 중 더 작은 값을 선택
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    // 결과 출력
    cout << dp[n] << "\n";

    return 0;
}