#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> adj[1001];
bool visited[1001];

// DFS: 재귀를 이용한 구현
void dfs(int now) {
    visited[now] = true;
    cout << now << " ";

    for (int next : adj[now]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

// BFS: 큐를 이용한 구현
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";

        for (int next : adj[now]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        // 양방향 간선
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // "번호가 낮은 순서대로" 방문하기 위해 정렬
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    // DFS 실행
    memset(visited, false, sizeof(visited));
    dfs(V);
    cout << "\n";

    // BFS 실행
    memset(visited, false, sizeof(visited));
    bfs(V);
    cout << "\n";

    return 0;
}