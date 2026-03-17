#include <iostream>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, H, W, N;
    cin >> T;

    while (T--) {
        cin >> H >> W >> N;

        // 1을 빼서 계산하고 나중에 1을 더하면 
        // N이 H의 배수일 때 생기는 예외가 자동으로 해결됩니다.
        int floor = (N - 1) % H + 1;
        int room = (N - 1) / H + 1;

        // 층수는 * 100을 해서 앞자리로 보내고 호수를 더함
        // room이 1자리수(예: 1)라도 101처럼 출력되어야 하므로 *100이 안전합니다.
        cout << floor * 100 + room << "\n";
    }

    return 0;
}