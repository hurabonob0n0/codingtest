#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(); cin.tie(NULL);
	int N, x;
	cin >> N;
	vector<int> v(N);
	for(int i =0; i<N; ++i)
		cin >> v[i];
	cin >> x;

	sort(v.begin(), v.end(),greater<int>());
	
	int y{}, start{}, end{1};

	// ai + aj = x 가 되는 쌍의 개수

	for (; start < N-2; ++start) {
		if (start == end)
			end += 1;
		while (v[start] + v[end] < x && end < N - 1) {
			end += 1;
		}
	}

}