#include <string>
#include <iostream>

using namespace std;

int main() 
{
	string word1, word2;
	cin >> word1 >> word2;
	int i = 0;
	int j = -1;
	for (i = 0; i < word1.size(); ++i) {
		size_t found = word2.find(word1[i]);
		if (found != string::npos) {
			j = (int)found;
			break;
		}
	}

	for (int y = 0; y < word2.size(); ++y) {
		for (int x = 0; x < word1.size(); ++x) {
			if (y == j)
				cout << word1[x];
			else if (x == i)
				cout << word2[y];
			else
				cout << '.';
		}
		cout << endl;
	}
}