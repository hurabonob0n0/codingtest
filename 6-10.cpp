#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(3));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> v[i][j];
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			v[i][j] += min(v[i - 1][(j + 1) % 3], v[i - 1][(j + 2) % 3]);
		}
	}

	cout << *min_element(v[n-1].begin(), v[n-1].end());
}

//8
//71 39 44
//32 83 55
//51 37 63
//89 29 100
//83 58 11
//65 13 15
//47 25 29
//60 66 19

//253