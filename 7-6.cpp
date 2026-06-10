#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// 다익스트라 함수
void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

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
                pq.push({ next_cost, next_node });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<vector<pair<int, int>>> reverse_graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        reverse_graph[v].push_back({ u, w }); // 방향을 뒤집은 그래프
    }

    vector<int> dist_from_x(n + 1, INF); // X에서 집으로
    vector<int> dist_to_x(n + 1, INF);   // 집에서 X로

    dijkstra(x, graph, dist_from_x);
    dijkstra(x, reverse_graph, dist_to_x);

    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        max_time = max(max_time, dist_from_x[i] + dist_to_x[i]);
    }

    cout << max_time << "\n";
    return 0;
}