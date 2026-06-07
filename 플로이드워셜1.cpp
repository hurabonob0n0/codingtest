#include <vector>
#include <algorithm>

using namespace std;

const int INF = 20000000; // 충분히 큰 값으로 초기화 (요금의 최댓값 고려)

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // 2차원 최단 거리 테이블 생성 및 무한대로 초기화
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // 자기 자신으로 가는 비용은 0으로 초기화
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // 주어진 요금 정보를 바탕으로 테이블 초기화 (양방향)
    for (int i = 0; i < fares.size(); i++) {
        int u = fares[i][0];
        int v = fares[i][1];
        int cost = fares[i][2];
        dist[u][v] = cost;
        dist[v][u] = cost;
    }

    // 플로이드-워셜 알고리즘 수행
    // k: 거쳐가는 노드, i: 출발 노드, j: 도착 노드
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int answer = INF;

    // STEP3: 모든 K에 대해 (S->K) + (K->A) + (K->B)의 최솟값 탐색
    for (int k = 1; k <= n; k++) {
        int current_cost = dist[s][k] + dist[k][a] + dist[k][b];
        if (current_cost < answer) {
            answer = current_cost;
        }
    }

    return answer;
}