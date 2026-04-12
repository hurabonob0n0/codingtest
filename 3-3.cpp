#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[301];
int dfn[301];      // 방문 순서
int low[301];      // 도달 가능한 최소 방문 순서
bool isCut[301];   // 단절점 여부
int timer = 0;

void findArticulationPoints(int u, int p = -1) {
    dfn[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (v == p) continue; // 부모로 돌아가는 간선 제외

        if (dfn[v]) {
            // 이미 방문한 노드라면 (Back-edge)
            low[u] = min(low[u], dfn[v]);
        }
        else {
            // 방문하지 않은 노드라면 (Tree-edge)
            children++;
            findArticulationPoints(v, u);
            low[u] = min(low[u], low[v]);

            // 단절점 판정 (루트가 아닐 때)
            if (p != -1 && low[v] >= dfn[u]) {
                isCut[u] = true;
            }
        }
    }

    // 단절점 판정 (루트일 때)
    if (p == -1 && children >= 2) {
        isCut[u] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 그래프가 하나로 연결되어 있다고 했으므로 1번 노드에서 시작
    if (N > 0) findArticulationPoints(1);

    vector<int> result;
    for (int i = 1; i <= N; i++) {
        if (isCut[i]) {
            result.push_back(i);
        }
    }

    // 결과 출력
    cout << result.size() << "\n";
    for (int node : result) {
        cout << node << "\n";
    }

    return 0;
}