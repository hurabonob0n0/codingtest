#include <iostream>
using namespace std;

int main() 
{
	string sen, explode;
	cin >> sen >> explode;
	int where;
	while (true) {
		where = sen.find(explode);
		if (where == string::npos)
			break;
		sen.erase(where,explode.size());
	}
	cout << sen;
}