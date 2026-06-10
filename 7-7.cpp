#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int v, e;

// 역추적을 위해 parent 배열을 매개변수로 받는 다익스트라
int dijkstra(int start, int end, vector<vector<pair<int, int>>>& graph, vector<int>& parent) {
    vector<int> dist(v, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto& edge : graph[now]) {
            int next_node = edge.first;
            int next_cost = cost + edge.second;

            if (next_cost < dist[next_node]) {
                dist[next_node] = next_cost;
                parent[next_node] = now; // 이전 노드 기록 (역추적용)
                pq.push({ next_cost, next_node });
            }
        }
    }
    return dist[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    vector<vector<pair<int, int>>> graph(v);

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // 양방향 그래프
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    vector<int> parent(v, -1);
    int original_dist = dijkstra(0, v - 1, graph, parent); // A 구하기

    // 도달 불가능 예외 처리
    if (original_dist == INF) {
        cout << 0 << "\n";
        return 0;
    }

    // 최단 경로 역추적 (도착지 V-1부터 시작점 0까지)
    vector<pair<int, int>> path_edges;
    int curr = v - 1;
    while (curr != 0) {
        int p = parent[curr];
        path_edges.push_back({ p, curr });
        curr = p;
    }

    int max_diff = 0;

    // 원래 최단 경로에 포함된 간선만 하나씩 가중치 2배 처리
    for (auto& edge : path_edges) {
        int n1 = edge.first;
        int n2 = edge.second;

        // 가중치 2배 (양방향 수정)
        for (auto& adj : graph[n1]) if (adj.first == n2) adj.second *= 2;
        for (auto& adj : graph[n2]) if (adj.first == n1) adj.second *= 2;

        vector<int> temp_parent(v, -1);
        int new_dist = dijkstra(0, v - 1, graph, temp_parent); // B 구하기

        if (new_dist != INF) {
            max_diff = max(max_diff, new_dist - original_dist); // B - A
        }

        // 가중치 원래대로 복구
        for (auto& adj : graph[n1]) if (adj.first == n2) adj.second /= 2;
        for (auto& adj : graph[n2]) if (adj.first == n1) adj.second /= 2;
    }

    cout << max_diff << "\n";
    return 0;
}