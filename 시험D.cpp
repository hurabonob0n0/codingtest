//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	int score;
//	cin >> n;
//	vector<int> v1(n - 2);
//	vector<int> v2(n - 2);
//	for (int i = 0; i < n-1; ++i) {
//		cin >> score;
//		if (i != n - 2)
//			v1[i] = score;
//		if (i != n - 3)
//			v2[i] = score;
//	}
//	cin >> score;
//
//	// 점화식 : dp[i] = max(dp[i-2] + v[i],dp[i-1]+v[i]);
//	vector<int> dp1(n - 2);
//	vector<int> dp2(n - 2);
//
//	for (int i = 0; i < n - 2; ++i) {
//		if (i == 0) {
//			dp1[i] = v1[i];
//			dp2[i] = v2[i];
//		}
//		if (i == 1) {
//			dp1[i] = dp1[i - 1] + v1[i];
//			dp2[i] = dp2[i - 1] + v2[i];
//		}
//		else {
//			dp1[i] = max(dp1[i-2] + dp1[i-1], dp1[i - 1] + v1[i]);
//			dp2[i] = max(dp2[i - 2] + dp2[i - 1], dp2[i - 1] + v2[i]);
//		}
//	}
//	cout << max(dp1[n - 3] + score, dp2[n - 3] + score);
//}

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

    // 인덱스를 1부터 사용하기 위해 크기를 n + 1로 할당
    vector<int> score(n + 1, 0);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> score[i];
    }

    // N이 1이거나 2일 때의 예외 처리 (매우 중요)
    if (n >= 1) dp[1] = score[1];
    if (n >= 2) dp[2] = score[1] + score[2];
    if (n >= 3) dp[3] = max(score[1] + score[3], score[2] + score[3]);

    // 점화식을 이용한 바텀업 DP 계산
    for (int i = 4; i <= n; ++i) {
        dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
    }

    // 마지막 계단에 도달했을 때의 최댓값 출력
    cout << dp[n] << "\n";

    return 0;
}