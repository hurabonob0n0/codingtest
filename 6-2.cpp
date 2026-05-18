#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    // 1. (n+1) x (m+1) 크기의 DP 테이블을 만들고 모두 0으로 채웁니다.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 2. puddles 배열을 돌면서 물웅덩이가 있는 자리에 -1을 찍어둡니다.
    for (int i = 0; i < puddles.size(); i++) {
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }

    // 시작 위치 초기화
    dp[1][1] = 1;

    // 3. (1, 1)부터 (n, m)까지 이중 for문을 돌면서 경로를 계산합니다.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue; // 시작 위치는 이미 1이므로 건너뜀

            if (dp[i][j] == -1) {
                // 물웅덩이면 0으로 바꿔서 다음 칸으로 가는 경로를 차단합니다.
                dp[i][j] = 0;
            }
            else {
                // 4. 물웅덩이가 아니라면 위쪽과 왼쪽의 값을 더해줍니다.
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
        }
    }

    return dp[n][m];
}