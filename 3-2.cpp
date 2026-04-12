#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 위치 범위: 0 ~ 100,000
const int MAX = 100001;
int dist[MAX]; // 각 위치까지 도달하는 데 걸린 시간 저장

int bfs(int start, int target) {
    if (start == target) return 0;

    queue<int> q;
    q.push(start);

    // 초기화: 방문하지 않은 곳은 -1 또는 0으로 설정 (여기선 0으로 사용)
    // 시작점 방문 표시
    dist[start] = 1; // 1부터 시작하여 최종 결과에서 1을 뺌 (방문 여부 확인 용이)

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // 이동 가능한 3가지 경우
        int next_steps[3] = { now - 1, now + 1, now * 2 };

        for (int next : next_steps) {
            // 1. 범위를 벗어나지 않는지 확인
            if (next >= 0 && next < MAX) {
                // 2. 이미 방문했는지 확인
                if (dist[next] == 0) {
                    dist[next] = dist[now] + 1;

                    // 동생을 찾았다면 종료
                    if (next == target) {
                        return dist[next] - 1;
                    }

                    q.push(next);
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    cout << bfs(N, K) << "\n";

    return 0;
}