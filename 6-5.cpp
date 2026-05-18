#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();

    // 1. 첫 번째 집을 터는 경우
    vector<int> dp1(n, 0);
    dp1[0] = money[0];
    dp1[1] = dp1[0]; // 두 번째 집은 못 터니까 첫 번째 집의 값을 그대로 가져감

    // 마지막 집(n-1)은 털 수 없으므로 n-2 까지만 반복
    for (int i = 2; i < n - 1; i++) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
    }

    // 2. 첫 번째 집을 털지 않는 경우
    vector<int> dp2(n, 0);
    dp2[0] = 0; // 첫 번째 집은 안 텀
    dp2[1] = money[1];

    // 마지막 집(n-1)까지 털 수 있으므로 n-1 까지 반복
    for (int i = 2; i < n; i++) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
    }

    // 두 경우 중 더 크게 훔친 금액을 반환
    return max(dp1[n - 2], dp2[n - 1]);
}