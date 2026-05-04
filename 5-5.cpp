#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> x;

// 주어진 높이(H)로 굴다리(0 ~ N)를 모두 밝힐 수 있는지 검증하는 함수
bool isCovered(int H) {
    int covered = 0; // 현재까지 연속해서 빛이 닿은 최대 위치

    for (int i = 0; i < M; i++) {
        // 다음 가로등이 비추는 가장 왼쪽 범위가 현재까지 밝혀진 끝부분보다 멀리 떨어져 있다면?
        // -> 중간에 어두운 빈 공간이 발생함을 의미
        if (x[i] - H > covered) {
            return false;
        }
        // 빈 공간이 없다면, 현재 가로등이 비추는 가장 오른쪽 범위로 covered 갱신
        covered = x[i] + H;
    }

    // 마지막 가로등까지 다 비췄을 때, 굴다리 끝(N)까지 도달했는지 확인
    return covered >= N;
}

int main() {
    // 입출력 속도 향상 (C++ 환경 필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. 입력 받기
    cin >> N >> M;
    x.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> x[i];
    }

    // 2. 이분 탐색 초기 설정
    int low = 1;
    int high = N;
    int result = N; // 정답을 저장할 변수 (최대 높이로 초기화)

    // 3. 이분 탐색 (매개변수 탐색) 진행
    while (low <= high) {
        int mid = low + (high - low) / 2; // (low + high) / 2 와 동일하나 오버플로우 방지용

        if (isCovered(mid)) {
            result = mid;       // 전체를 비출 수 있으므로 일단 정답 기록
            high = mid - 1;     // 최소 높이를 찾기 위해 더 낮은 높이 탐색
        }
        else {
            low = mid + 1;      // 전체를 비출 수 없으므로 가로등 높이를 높여야 함
        }
    }

    // 4. 결과 출력
    cout << result << "\n";

    return 0;
}