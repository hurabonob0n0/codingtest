#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int w, h;
int board[51][51];
bool visited[51][51];

// 8¹æÇâ
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void dfs(int y, int x);

int main() {
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        memset(visited, false, sizeof(visited));

        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                cin >> board[y][x];

        int cnt = 0;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (board[y][x] == 1 && !visited[y][x]) {
                    dfs(y, x);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }
}

void dfs(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        if (!visited[ny][nx] && board[ny][nx] == 1)
            dfs(ny, nx);
    }
}