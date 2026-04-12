#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> vValue(N);
	for (int i = 0; i < N; ++i) {
		cin >> vValue[i];
	}
	int maxValue = 0;
	for (int i = 0; i < N - 3; ++i) {
		for (int j = i + 1; j < N - 2; ++j) {
			for (int k = j + 1; k < N - 1; ++k) {
				int v = vValue[i] + vValue[j] + vValue[k];
				if(v <= K && v > maxValue) {
					maxValue = v;
				}
				if (v == K) {
					cout << v;
					return 0;
				}
			}
		}
	}
	cout << maxValue;
}
