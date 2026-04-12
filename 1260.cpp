#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int nxt : graph[v]) {
        if (!visited[nxt]) dfs(nxt);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";
        for (int nxt : graph[v]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());

    dfs(V);
    cout << "\n";

    fill(visited, visited + 1001, false);

    bfs(V);
}