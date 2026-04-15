#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool check(const vector<vector<int>>& board)
{
	string test;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int n = board[i][j];
			if (n == 0)
				continue;
			if (test.find(n) == string::npos)
				test+=n;
			else
				return false;
		}
		test.clear();
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int n = board[j][i];
			if (n == 0)
				continue;
			if (test.find(n) == string::npos)
				test += n;
			else
				return false;
		}
		test.clear();
	}

	for (int k = 0; k < 3; ++k) {
		for (int l = 0; l < 3; ++l) {
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					int n = board[i+3*k][j + 3 * l];
					if (n == 0)
						continue;
					if (test.find(n) == string::npos)
						test += n;
					else
						return false;
				}
				test.clear();
			}
		}
	}

	return true;
}

int main() 
{
	int t;
	char c;
	cin >> t;
	vector<vector<int>> board(9,vector<int>(9));
	while (t--) {
		int n = 0;
		for (int i = 0; i < 13; ++i) {
			for(int j =0; j<13; ++j){
				cin >> c;
				if (c == '+' || c == '-' || c == '|')
					continue;
				else if (c == '.')
					++n;
				else {
					int t = atoi(&c);
					board[n / 9][n % 9] = t;
					++n;
				}
					
			}
		}

		/*for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << board[i][j];
			}
			cout << endl;
		}*/

		if (check(board))
			cout << 'Y' << endl;
		else
			cout << 'N' << endl;
		board.clear();
		board.resize(9);
		for (int i = 0; i < 9; ++i) {
			board[i].resize(9);
		}
	}
}