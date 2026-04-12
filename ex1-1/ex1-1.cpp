#include <iostream>
using namespace std;

int main() {
	char c;
	int count = 0;
	int turn = 0;
	int row = 0;
	while (turn < 64) {
		cin >> c;
		if(c == 'F' && turn % 2 == row % 2){
			count++;
		}
		++turn;
		if (turn % 8 == 0) {
			row++;
		}
	}
	cout << count;
}