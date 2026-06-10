#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

int parent_node[100001];

int find(int x) {
    if (parent_node[x] == x) return x;
    return parent_node[x] = find(parent_node[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent_node[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 1; i <= n; i++) parent_node[i] = i;
    for (int i = 0; i < m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), cmp);

    int total_cost = 0;
    int max_cost = 0;

    for (int i = 0; i < m; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            unite(edges[i].u, edges[i].v);
            total_cost += edges[i].w;
            max_cost = edges[i].w; // 정렬되어 있으므로 마지막에 더해진 간선이 제일 비쌈
        }
    }

    cout << total_cost - max_cost << "\n";
    return 0;
}