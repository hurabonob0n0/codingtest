//5 1
//rokod

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, j;
	cin >> n >> j;
	vector<int> cs(4);
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		if (c == 'k')
			++cs[0];
		if (c == 'r')
			++cs[1];
		if (c == 'o')
			++cs[2];
		if (c == 'd')
			++cs[3];
	}


	vector<int>cs2{ cs };

	for (int k = 0; k < 4; ++k) {
		++cs2[k];
		for (int i = 0; i < j; ++i) {

		}
	}

}