#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> arr(10);
	for (int i = 0; i < 10; ++i) {
		cout << rand() % 10 + 1 << " ";
	}
	
}