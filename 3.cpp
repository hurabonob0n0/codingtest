#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
	int n;
	int score;
};

int main()
{
	int num;
	cin >> num;
	vector<info> hjang(num);
	vector<info> hwon(num);
	vector<info> finalresult(num);

	int n;
	for (int j = 0; j < num; ++j) {
		cin >> n;
		hjang[j] = info{ n, num-j };
		
	}

	for (int j = 0; j < num; ++j) {
		cin >> n;
		hwon[j] = info{ j,n };
	}

	std::sort(hwon.begin(), hwon.end(), [](info& a, info& b) {
		return a.score > b.score;
		});

	for (int i = 0; i < num; ++i) {
		hwon[i].score = num - i;
	}

	std::sort(hjang.begin(), hjang.end(), [](info& a, info& b) {
		return a.n < b.n;
		});

	std::sort(hwon.begin(), hwon.end(), [](info& a, info& b) {
		return a.n < b.n;
		});

	for (int i = 0; i < num; ++i) {
		finalresult[i] = info{ i,hjang[i].score + hwon[i].score };
	}

	std::sort(finalresult.begin(), finalresult.end(), [](info& a, info& b) {
		return a.score > b.score;
		});

	for (int i = 0; i < num; ++i) {
		int n = finalresult[i].n;
		if (n < 10)
			cout << i+1 << ". " << "Kod0" << n+1 << " (" << finalresult[i].score << ")" << endl;
		else if ( n >= 10 && i < num -1)
			cout << i+1 << ". " << "Kod" << n+1 << " (" << finalresult[i].score << ")" << endl;
		else
			cout << i + 1 << ". " << "Kod" << n + 1 << " (" << finalresult[i].score << ")";
	}
}