#include <iostream>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	int i, j;
	/*for (i = 0; i < B.size(); ++i) {
		j = A.find(B[i]);
		if (j != string::npos)
			break;
	}*/
	for (j = 0; j < A.size(); ++j) {
		i = B.find(A[j]);
		if (i != string::npos)
			break;
	}
	//i행에 A 출력하고 , j열에 B 출력

	for (int c = 0; c < B.size(); ++c) {
		for (int r = 0; r < A.size(); ++r) {
			if (c == i)
				cout << A[r];
			else if (r == j)
				cout << B[c];
			else
				cout << '.';
		}
		cout << endl;
	}
}