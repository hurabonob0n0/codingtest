#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;

    int total_min_time = 0;

    for (int i = 1; i <= n; i++) {
        int time, cnt;
        cin >> time >> cnt;

        int max_pre_time = 0;
        for (int j = 0; j < cnt; j++) {
            int pre;
            cin >> pre;
            max_pre_time = max(max_pre_time, dp[pre]);
        }

        dp[i] = time + max_pre_time; // 점화식: max(이전 작업들) + 내 작업 시간
        total_min_time = max(total_min_time, dp[i]);
    }

    cout << total_min_time << "\n";
    return 0;
}