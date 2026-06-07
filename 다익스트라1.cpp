#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9; // 무한대를 의미하는 값

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    // 그래프 초기화: 정점 번호가 1부터 시작하므로 N+1 크기로 할당
    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // 양방향 길이므로 양쪽 모두에 추가
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    // 최단 거리(최소 여물) 테이블을 INF로 초기화
    vector<int> dist(N + 1, INF);

    // 우선순위 큐: {누적 비용, 현재 노드} (최소 힙 구현을 위해 greater 사용)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 시작점 설정 (헛간 1)
    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // 이미 처리된 적이 있는 노드라면 무시
        if (dist[current_node] < current_cost) continue;

        // 인접한 노드들을 확인
        for (int i = 0; i < graph[current_node].size(); i++) {
            int next_node = graph[current_node][i].first;
            int next_cost = current_cost + graph[current_node][i].second;

            // 더 적은 비용으로 갈 수 있는 경로를 찾았다면 갱신
            if (next_cost < dist[next_node]) {
                dist[next_node] = next_cost;
                pq.push({ next_cost, next_node });
            }
        }
    }

    // 헛간 N까지의 최소 여물 비용 출력
    cout << dist[N] << "\n";

    return 0;
}