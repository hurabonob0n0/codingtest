#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	int iValue;

	cin >> N >> K;
	vector<int> vValue(N);

	for (int i = 0; i < N; ++i) {
		cin >> vValue[i];
	}

	int minCnt = 0;
	while (--N >= 0) {
		minCnt += K / vValue[N];
		K %= vValue[N];
		if (K == 0)
			break;
	}

	cout << minCnt;

}