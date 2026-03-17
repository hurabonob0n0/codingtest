#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> vNums(n);
	for (int i = 0; i < n; ++i)
		cin >> vNums[i];

	int maxVal = 0;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int value = vNums[i] + vNums[j] + vNums[k];
				if (value <= m && maxVal < value) {
					maxVal = value;
				}
			}
		}
	}

	cout << maxVal;
}