#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	vector<char> sen;
	istreambuf_iterator<char> it(cin), end;
	while (it != end) {
		if (*it == '\n')
			++it;
		else {
			sen.push_back(*it);
			++it;
		}
	}

	
}