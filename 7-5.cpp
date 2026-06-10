#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 40000000; // 최대 노드수(200) * 최대 요금(100,000)보다 크게 설정

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // 2차원 최단거리 배열 초기화
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    // 간선 정보 입력
    for (auto& f : fares) {
        dist[f[0]][f[1]] = f[2];
        dist[f[1]][f[0]] = f[2];
    }

    // 플로이드-워셜 수행
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 최소 요금 탐색 (k지점까지 합승 후 찢어지는 경우)
    int answer = INF;
    for (int k = 1; k <= n; k++) {
        answer = min(answer, dist[s][k] + dist[k][a] + dist[k][b]);
    }

    return answer;
}