#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 최적화 (C++에서 필수적)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> trees(N);
    long long max_height = 0;

    // 나무 높이 입력 및 가장 높은 나무 찾기
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        if (trees[i] > max_height) {
            max_height = trees[i];
        }
    }

    // 이분 탐색 초기 설정
    long long low = 0;
    long long high = max_height;
    long long result = 0; // 정답을 저장할 변수

    // 이분 탐색 진행
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long total_wood = 0;

        // mid 높이로 잘랐을 때 얻을 수 있는 나무의 양 계산
        for (int i = 0; i < N; i++) {
            if (trees[i] > mid) {
                total_wood += (trees[i] - mid);
            }
        }

        // 조건 검사: 적어도 M미터 이상의 나무를 얻었는가?
        if (total_wood >= M) {
            result = mid;       // 가능한 높이이므로 일단 정답에 저장
            low = mid + 1;      // 절단기 높이를 더 높일 수 있는지 확인 (최댓값 찾기)
        }
        else {
            high = mid - 1;     // 잘린 나무가 부족하므로 절단기 높이를 낮춰야 함
        }
    }

    // 최댓값 출력
    cout << result << "\n";

    return 0;
}