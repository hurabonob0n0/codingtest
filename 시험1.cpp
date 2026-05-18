#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> values(n);
	for (int i = 0; i < n; ++i) {
		cin >> values[i];
	}
	sort(values.begin(), values.end(), [](int& a, int& b) {return a > b; });
	int i = 0;
	for (auto it = values.begin(); it < values.end();) {
		++i;
		if (i % 3 == 0)
			it = values.erase(it);
		else
			++it;
	}
	long long solution = 0;
	for (auto& v : values)
		solution += v;
	cout << solution;
}
//4
//3
//2
//3
//2