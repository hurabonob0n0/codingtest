#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 강연이 하나도 없는 경우(n=0) 예외 처리
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    // pair<기한(d), 강연료(p)> 형태로 저장할 벡터
    // 기한을 기준으로 정렬하기 위해 기한을 first에 둡니다.
    vector<pair<int, int>> lectures(n);
    for (int i = 0; i < n; i++) {
        cin >> lectures[i].second >> lectures[i].first;
    }

    // 1. 기한(d)을 기준으로 오름차순 정렬
    // 마감이 빨리 끝나는 강연부터 처리합니다.
    sort(lectures.begin(), lectures.end());

    // 2. 강연료를 담을 최소 힙 (우선순위 큐)
    // 가장 싼 강연료가 맨 위에 오도록 greater<int> 사용
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        // 일단 현재 강연의 페이를 스케줄장(우선순위 큐)에 넣습니다.
        pq.push(lectures[i].second);

        // 우선순위 큐의 크기 = 현재까지 수락한 강연의 개수 (즉, 소요되는 일수)
        // 만약 수락한 강연 개수가 현재 강연의 마감 기한보다 커진다면?
        // 기한 내에 다 할 수 없다는 뜻이므로, 가장 페이가 적은 강연을 포기합니다.
        if (pq.size() > lectures[i].first) {
            pq.pop(); // 최소 힙이므로 가장 적은 강연료가 빠져나감
        }
    }

    // 3. 힙에 최종적으로 살아남은 강연료들을 모두 더합니다.
    int total_pay = 0;
    while (!pq.empty()) {
        total_pay += pq.top();
        pq.pop();
    }

    cout << total_pay << "\n";

    return 0;
}