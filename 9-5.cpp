#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M;
vector<pair<long long, long long>> intervals;

// 간격 D를 유지하며 N명의 학생을 모두 배치할 수 있는지 확인하는 함수
bool check(long long D) {
    long long count = 0;
    long long current_pos = -2e18; // 처음엔 무조건 첫 구간에 배치되도록 아주 작은 값 설정

    for (int i = 0; i < M; i++) {
        long long start = intervals[i].first;
        long long end = intervals[i].second;

        // 현재 위치에서 D만큼 떨어진 곳이 구간 시작점보다 작다면 시작점으로 갱신
        current_pos = max(current_pos + D, start);

        // 현재 구간 안에서 배치할 수 있는 학생들을 모두 배치
        while (current_pos <= end) {
            count++;
            if (count >= N) return true; // N명 다 배치했으면 성공
            current_pos += D; // 다음 배치를 위해 D만큼 이동
        }
    }
    return count >= N;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;

    intervals.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end());

    // 이분 탐색 (Search Space)
    long long low = 1;
    long long high = intervals.back().second - intervals.front().first;
    long long answer = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (check(mid)) {
            answer = mid; // 배치가 가능하면 일단 기록해두고 거리를 늘림
            low = mid + 1;
        }
        else {
            high = mid - 1; // 배치가 불가능하면 거리를 좁힘
        }
    }

    cout << answer << "\n";
    return 0;
}