#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; ++i) {
		dp[i] = v[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (v[i] > v[j]) {
				dp[i] = max(dp[i], dp[j] + v[i]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
		cout << dp[i] << " ";

	cout << endl << *max_element(dp.begin(), dp.end()) << "\n";
}