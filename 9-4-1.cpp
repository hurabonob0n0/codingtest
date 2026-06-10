#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int r, c;
	cin >> r>> c;
	vector<vector<int>> v(r, vector<int>(c));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> v[r][c];
		}
	}
	int n;
	cin >> n;
	vector<int> xy(n);
	for (int i = 0; i < n * 4; ++i) {
		cin >> xy[i];
	}

	vector<vector<int>> dp(r + 1, vector<int>(c + 1));
	// dp[r][c] = dp[r][c-1] + dp[r-1][c] - dp[r-1][c-1] + v[r][c]

}