#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> houses;

// 주어진 거리(dist)를 최소 간격으로 유지하며 C개 이상의 공유기를 설치할 수 있는지 검증
bool canInstall(int dist) {
    int count = 1; // 첫 번째 집에는 무조건 설치한다고 가정
    int last_installed = houses[0];

    for (int i = 1; i < N; i++) {
        // 현재 집과 마지막 설치된 집의 거리가 dist 이상이면 공유기 설치
        if (houses[i] - last_installed >= dist) {
            count++;
            last_installed = houses[i];
        }
    }

    // 설치된 공유기 개수가 C개 이상인지 반환
    return count >= C;
}

int main() {
    // 입출력 속도 향상 (C++ 환경 필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. 입력 받기
    cin >> N >> C;
    houses.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }

    // 2. 이분 탐색을 위한 오름차순 정렬
    sort(houses.begin(), houses.end());

    // 3. 이분 탐색 초기 설정 (거리를 기준으로 탐색)
    int low = 1; // 가능한 최소 거리
    int high = houses[N - 1] - houses[0]; // 가능한 최대 거리
    int result = 0;

    // 4. 이분 탐색 진행
    while (low <= high) {
        int mid = low + (high - low) / 2; // 오버플로우 방지용 중간값 계산

        if (canInstall(mid)) {
            result = mid;       // C개 이상 설치 가능하므로 일단 정답 기록
            low = mid + 1;      // '최대' 거리를 구해야 하므로 간격을 더 늘려봄
        }
        else {
            high = mid - 1;     // C개를 다 설치하지 못했으므로 간격을 좁혀야 함
        }
    }

    // 5. 결과 출력
    cout << result << "\n";

    return 0;
}