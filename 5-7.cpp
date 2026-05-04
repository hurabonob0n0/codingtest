#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> requests(N);
    int max_request = 0;
    long long total_request = 0; // 모든 요청의 합을 저장할 변수

    // 예산 요청액 입력 받기 및 최댓값, 총합 구하기
    for (int i = 0; i < N; i++) {
        cin >> requests[i];
        if (requests[i] > max_request) {
            max_request = requests[i];
        }
        total_request += requests[i];
    }

    long long M;
    cin >> M;

    // 1. 모든 요청이 배정될 수 있는 경우 (조건 분기)
    if (total_request <= M) {
        cout << max_request << "\n";
        return 0; // 프로그램 바로 종료
    }

    // 2. 모든 요청을 배정할 수 없는 경우 (이분 탐색 진행)
    int low = 0;
    int high = max_request;
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2; // 임시 상한액
        long long current_budget_sum = 0;

        // 임시 상한액(mid)을 적용했을 때의 총 예산 소요량 계산
        for (int i = 0; i < N; i++) {
            if (requests[i] > mid) {
                current_budget_sum += mid;      // 상한액 이상 요청한 곳은 상한액만 배정
            }
            else {
                current_budget_sum += requests[i]; // 상한액 이하 요청한 곳은 그대로 배정
            }
        }

        // 3. 예산이 배정 가능한지 확인하고 범위 조절
        if (current_budget_sum <= M) {
            result = mid;       // 배정 가능하므로 일단 정답 기록
            low = mid + 1;      // 가능한 한 '최대' 예산을 쓰기 위해 상한액을 높여봄
        }
        else {
            high = mid - 1;     // 예산을 초과했으므로 상한액을 낮춰야 함
        }
    }

    // 결과 출력
    cout << result << "\n";

    return 0;
}