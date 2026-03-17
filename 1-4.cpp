#include <list>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sentence_str;
	string explode;
	cin >> sentence_str >> explode;
	while (true) {
		size_t found = sentence_str.find(explode);
		if (found == string::npos) break;
		sentence_str.erase(found, explode.size());
	}
	cout << sentence_str;
}