#include <iostream>

using namespace std;

int main() {
    // 입출력 속도 향상 (백준 필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int count = 0; // 배달할 봉지의 개수

    while (n >= 0) {
        // 1. 현재 남은 무게가 5의 배수라면?
        // 5로 나눈 몫을 더해주고 바로 종료하는 것이 가장 봉지를 적게 쓰는 방법입니다.
        if (n % 5 == 0) {
            count += (n / 5);
            cout << count << "\n";
            return 0;
        }

        // 2. 5의 배수가 아니라면 3kg 봉지를 하나 씁니다.
        n -= 3;
        count++;
    }

    // 3. while문을 빠져나왔다는 것은 정확히 N 킬로그램을 만들 수 없다는 뜻입니다.
    cout << -1 << "\n";

    return 0;
}