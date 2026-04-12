#include <iostream>
using namespace std;

int main() {
	int T;
	int H, W, N;
	cin >> T;
	while (T--) {
		cin >> H >> W >> N;
		int h, n;
		h = (N) % H;
		n = N / H + 1;

		if (h == 0)
		{
			h = H;
			n = N / H;
		}

		cout << h * 100 + n << endl;
	}
}