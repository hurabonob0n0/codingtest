#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;

    string initial, target;
    cin >> initial >> target;

    int w_to_b = 0; // 초기상태 W -> 목표상태 B인 경우
    int b_to_w = 0; // 초기상태 B -> 목표상태 W인 경우

    for (int i = 0; i < N; ++i) {
        if (initial[i] != target[i]) {
            if (initial[i] == 'W') {
                w_to_b++;
            }
            else {
                b_to_w++;
            }
        }
    }

    // 두 차이값 중 큰 값이 최소 작업 횟수입니다.
    cout << max(w_to_b, b_to_w) << "\n";
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}