#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int x;
    cin >> x;

    sort(a.begin(), a.end()); // 투 포인터를 위한 정렬

    int left = 0, right = n - 1;
    int count = 0;

    while (left < right) {
        int sum = a[left] + a[right];
        if (sum == x) {
            count++;
            left++;
            right--;
        }
        else if (sum < x) {
            left++; // 합이 작으면 값을 키움
        }
        else {
            right--; // 합이 크면 값을 줄임
        }
    }

    cout << count << "\n";
    return 0;
}