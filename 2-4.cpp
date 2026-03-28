#include <iostream>
#include <vector>

using namespace std;

struct food {
	int t;
	int d;
	int g;
};

vector<food> combi(vector<food>& foods , int n) {
	vector<food> ret;
	if (n == 1) {
		for (auto f : foods)
			ret.push_back(f);
	}

	else (n > 1)
}

int main()
{
	int n;
	int in;
	vector<food> foods;
	int max[4];

	cin >> n;
	for (int i = 0; i < n; ++i) {
		food nfood;
		for (int j = 0; j < 3; ++j) {
			cin >> in;
			if (j == 0)
				nfood.t = in;
			else if (j == 1)
				nfood.d = in;
			else
				nfood.g = in;
		}
		foods.push_back(nfood);
	}
	for (int i = 0; i < 4; ++i)
		cin >> max[i];

}