#include <iostream>
#include <vector>
#include <algorithm> // sort를 위해 필요

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> vNums(n);
    for (int i = 0; i < n; ++i)
        cin >> vNums[i];

    // 1. 투 포인터의 전제 조건: 정렬!
    sort(vNums.begin(), vNums.end());

    int maxVal = 0;

    // 2. 첫 번째 카드 i를 고정 (O(N))
    for (int i = 0; i < n - 2; ++i) {
        // i번째 카드가 이미 M보다 크면 이후는 볼 필요도 없음 (가지치기)
        if (vNums[i] > m) break;

        int left = i + 1;
        int right = n - 1;

        // 3. left와 right를 좁혀가며 탐색 (O(N))
        while (left < right) {
            int value = vNums[i] + vNums[left] + vNums[right];

            if (value == m) {
                // 정확히 M을 찾으면 이보다 좋은 답은 없으므로 즉시 종료
                cout << m;
                return 0;
            }

            if (value < m) {
                // M보다 작으면 일단 후보로 등록하고, 더 큰 값을 찾아봄
                if (maxVal < value) maxVal = value;
                left++;
            }
            else {
                // M보다 크면 합을 줄여야 하므로 오른쪽 포인터를 당김
                right--;
            }
        }
    }

    cout << maxVal;
    return 0;
}