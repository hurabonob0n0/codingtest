#include <iostream>
#include <vector>
#include <algorithm> // max 함수 사용

using namespace std;

int R, C;
int max_dist = 0;
int dx[] = { 0, 0, 1, -1 }; // 상하좌우 이동을 위한 좌표
int dy[] = { 1, -1, 0, 0 };

// board는 전역 혹은 참조로 전달, visited는 알파벳 방문 여부
void DFS(const vector<vector<char>>& board, bool visited[], int x, int y, int count) {
    // 1. 현재 경로의 길이를 최댓값과 비교하여 갱신
    max_dist = max(max_dist, count);

    // 알파벳은 총 26개이므로 26에 도달하면 더 이상 탐색할 필요 없음 (최적화)
    if (max_dist == 26) {
        cout << 26;
        exit(0);
    }

    // 2. 상하좌우 네 방향 확인
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 보드 범위 내에 있는지 확인
        if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
            int alphabet_idx = board[ny][nx] - 'A';

            // 3. 아직 방문하지 않은 알파벳인 경우
            if (!visited[alphabet_idx]) {
                visited[alphabet_idx] = true;        // 방문 표시
                DFS(board, visited, nx, ny, count + 1); // 재귀 호출
                visited[alphabet_idx] = false;       // ★백트래킹: 다시 돌아왔을 때 방문 표시 해제
            }
        }
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    vector<vector<char>> board(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    bool visited[26] = { false };

    // 시작 지점(0,0)의 알파벳 처리
    visited[board[0][0] - 'A'] = true;

    // DFS 시작 (x, y, 현재 칸 수)
    DFS(board, visited, 0, 0, 1);

    cout << max_dist << endl;

    return 0;
}