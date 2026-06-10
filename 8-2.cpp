#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> req(m);
    for (int i = 0; i < m; i++) {
        cin >> req[i].first >> req[i].second;
    }

    sort(req.begin(), req.end());

    for (int i = 1; i <= n; i++) dp[i] = 1; // 모든 과목은 최소 1학기에 수강 가능

    for (int i = 0; i < m; i++) {
        int a = req[i].first;
        int b = req[i].second;
        dp[b] = max(dp[b], dp[a] + 1);
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    return 0;
}