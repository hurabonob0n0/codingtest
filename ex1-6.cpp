#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int res[3];
    int n[3];
    char sdt[3];
    char sang[3] = { ' ', ' ', ' ' }; // 공백으로 초기화

    for (int t = 0; t < 3; ++t) {
        cin >> n[t];      // 점수(int) 읽기
        cin >> sdt[t];    // 보너스(S, D, T) 읽기

        // 다음 문자가 '*'이나 '#'인지 확인 (가져오지는 않음)
        char next = cin.peek();
        if (next == '*' || next == '#') {
            cin >> sang[t]; // 옵션이 맞다면 그때서야 실제로 읽기
        }
    }

	
}