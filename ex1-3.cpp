#include <iostream>
using namespace std;

int main()
{
	int T;
	int N;
	string Origin, Change;

	cin >> T;
	while (T--) {
		cin >> N;
		cin >> Origin >> Change;
		int WtB{}, BtW{};
		for (int i = 0; i < N; ++i) {
			if (Origin[i] == 'W' && Change[i] == 'B')
				++WtB;
			else if (Origin[i] == 'B' && Change[i] == 'W')
				++BtW;
		}
		int res = min(WtB, BtW) + abs(WtB - BtW);
		cout << res << endl;
	}
}

//3
//5
//WBBWW
//WBWBW
//7
//BBBBBBB
//BWBWBWB
//4
//WWBB
//BBWB