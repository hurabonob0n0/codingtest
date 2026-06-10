#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // 다음 순열이 존재하면 true 반환 후 배열 자체를 변환시킴
    if (next_permutation(v.begin(), v.end())) {
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    else {
        // 마지막 순열이라 다음이 없으면 -1 출력
        cout << -1 << "\n";
    }
    return 0;
}