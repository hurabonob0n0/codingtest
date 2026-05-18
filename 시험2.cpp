#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // min 함수 사용

using namespace std;

int r, c;

int check_snow(const vector<string>& grid, int i, int j) {
    // 중심 (i, j)에서 상하좌우 및 대각선으로 뻗어나갈 수 있는 최대 안전 거리
    int max_dist = min({ i, j, r - 1 - i, c - 1 - j });
    int size = 0;

    // k는 뻗어나가는 거리 (크기)
    for (int k = 1; k <= max_dist; ++k) {
        // 8방향 문자가 모두 올바른지 검사
        if (grid[i - k][j - k] == '\\' && grid[i - k][j] == '|' && grid[i - k][j + k] == '/' &&
            grid[i][j - k] == '-' && grid[i][j + k] == '-' &&
            grid[i + k][j - k] == '/' && grid[i + k][j] == '|' && grid[i + k][j + k] == '\\') {

            size = k; // 모두 만족하면 현재 거리 k를 눈송이 크기로 갱신
        }
        else {
            break; // 하나라도 어긋나면 연속성이 깨졌으므로 즉시 탐색 중단
        }
    }
    return size;
}

int main() {
    // C++ 입출력 속도 향상 (코딩 테스트 필수 설정)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P;
    if (!(cin >> P)) return 0;

    while (P--) {
        cin >> r >> c;
        vector<string> grid(r);

        // vector<string>을 사용하면 한 줄씩 그대로 입력받을 수 있어 매우 편리합니다.
        for (int i = 0; i < r; ++i) {
            cin >> grid[i];
        }

        int max_snowflake = 0;

        // 2차원 배열의 모든 칸을 순회하며 중심점(+)을 찾습니다.
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == '+') {
                    max_snowflake = max(max_snowflake, check_snow(grid, i, j));
                }
            }
        }
        cout << max_snowflake << "\n";
    }

    return 0;
}