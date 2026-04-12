#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> vValue(N);
	int cnt{};
	
	for (int i = 0; i < N; ++i) {
		cin >> vValue[i];
	}
	for (int i = N - 1; i >= 0; --i) {
		cnt += K / vValue[i];
		K %= vValue[i];
	}

	cout << cnt;
}