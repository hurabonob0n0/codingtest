#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n;
    if (!(cin >> c >> n)) return 0;

    vector<int> chickens(c);
    for (int i = 0; i < c; i++) {
        cin >> chickens[i];
    }
    // 닭의 시간을 오름차순 정렬
    sort(chickens.begin(), chickens.end());

    // 소의 시간을 (시작 시간, 종료 시간) 순으로 오름차순 정렬
    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end());

    priority_queue<int, vector<int>, greater<int>> pq; // 종료 시간을 담을 최소 힙
    int cow_idx = 0;
    int count = 0;

    for (int i = 0; i < c; i++) {
        // 현재 닭의 시간보다 시작 시간이 작거나 같은 소의 종료 시간을 힙에 추가
        while (cow_idx < n && cows[cow_idx].first <= chickens[i]) {
            pq.push(cows[cow_idx].second);
            cow_idx++;
        }

        // 이미 종료 시간이 지나버린 소들은 힙에서 제거
        while (!pq.empty() && pq.top() < chickens[i]) {
            pq.pop();
        }

        // 가장 빨리 끝나는 소 매칭
        if (!pq.empty()) {
            count++;
            pq.pop();
        }
    }

    cout << count << "\n";
    return 0;
}