#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;

	cin >> n >> s;
	
	int cupholders{ 1 };

	while (true) {
		int f1 = s.find('S');
		int f2 = s.find('LL');
		
		if (f1 == string::npos && f2 == string::npos)
			break;
		else if (f1 == string::npos && f2 != string::npos) {
			cupholders++;
			s.erase(f2, 2);
		}
		else if (f1 != string::npos && f2 == string::npos) {
			cupholders++;
			s.erase(f1, 1);
		}
		else {
			cupholders++;
			s.erase(f1, 1);
		}
	}

	cout << min(n, cupholders);
}