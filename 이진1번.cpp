#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> trees(N);
    long long max_tree = 0;

    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        if (trees[i] > max_tree) {
            max_tree = trees[i];
        }
    }

    long long low = 0;
    long long high = max_tree;
    long long result = 0;

    // 이분 탐색 시작
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long total_wood = 0;

        // mid 높이로 잘랐을 때 얻을 수 있는 나무 양 계산
        for (int i = 0; i < N; i++) {
            if (trees[i] > mid) {
                total_wood += (trees[i] - mid);
            }
        }

        // 조건 판별 및 범위 갱신
        if (total_wood >= M) {
            result = mid;       // M 이상을 얻었으므로 일단 정답 후보로 저장
            low = mid + 1;      // 더 높게 잘라볼 수 있는지 확인
        }
        else {
            high = mid - 1;     // 나무가 부족하므로 더 낮게 잘라야 함
        }
    }

    cout << result << "\n";

    return 0;
}