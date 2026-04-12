#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000;
int visited[100001];

int main() {
    int N, K;
    cin >> N >> K;

    queue<int> q;
    q.push(N);
    visited[N] = 1;   // 0이랑 구분하려고 1부터 시작

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == K) {
            cout << visited[x] - 1; // 처음을 1로 했으니까 -1
            return 0;
        }

        int nx[3] = { x - 1, x + 1, x * 2 };

        for (int i = 0; i < 3; i++) {
            int next = nx[i];

            if (next < 0 || next > MAX) continue; // 범위 체크
            if (visited[next] != 0) continue;     // 이미 방문했음

            visited[next] = visited[x] + 1;        // 거리 증가
            q.push(next);
        }
    }
}