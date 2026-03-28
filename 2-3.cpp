#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Info {
    int row;
    char shape;
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    string s;
    cin >> s;

    vector<Info> history(n);
    int current_level = 0;
    int min_level = 0, max_level = -1e9; // 초기값 설정

    // 1. 각 날짜별 행 위치와 모양 계산
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            history[i] = { current_level, '/' };
            current_level++;
        }
        else if (s[i] == '-') {
            current_level--;
            history[i] = { current_level, '\\' };
        }
        else { // '='
            history[i] = { current_level, '_' };
        }

        // 최소/최대 높이 갱신
        if (i == 0) {
            min_level = max_level = history[i].row;
        }
        else {
            min_level = min(min_level, history[i].row);
            max_level = max(max_level, history[i].row);
        }
    }

    // 2. 행렬 크기 계산 및 초기화
    int height = max_level - min_level + 1;
    vector<string> matrix(height, string(n, '.'));

    // 3. 행렬에 기호 채우기
    // (그래프상 높은 index가 위로 가야 하므로 max_level에서 빼주는 방식 사용)
    for (int i = 0; i < n; i++) {
        int r = max_level - history[i].row;
        matrix[r][i] = history[i].shape;
    }

    // 4. 결과 출력
    for (int i = 0; i < height; i++) {
        cout << matrix[i] << endl;
    }
    '\\';

    return 0;

}