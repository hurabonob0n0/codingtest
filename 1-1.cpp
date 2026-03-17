#include <iostream>
#include <iterator>

using namespace std;

int main() {
    istreambuf_iterator<char> it(cin), end;
    int cnt = 0;
    int n = 0;
    
    while (it != end && n < 64) {
        if(*it == '\n' || *it == '\r') {
            ++it;
		}
        else {
            int row = n / 8;
            int col = n % 8;
            if ((row + col) % 2 == 0 && *it == 'F') {
                ++cnt;
            }
            ++it;
            ++n; 
        }
    }
    cout << endl << cnt;
}