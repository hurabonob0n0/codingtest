#include <string>
using namespace std;

int solution(string dartResult) {
    int size = dartResult.size();
    int num{};
    int res[3]{};
	int index = -1;
	
    for (int i = 0; i < size; ++i) {
        if (dartResult[i] >= '0' && dartResult[i] <= '9') {
            if (dartResult[i + 1] == '0') {
                num = 10;
                ++i;
                ++index;
            }
            else {
                num = dartResult[i] - '0';
                ++index;
            }
        }
        else if (dartResult[i] == 'S')
            res[index] = num;
        else if (dartResult[i] == 'D')
            res[index] = num *= num;
        else if (dartResult[i] == 'T')
            res[index] = num *= num * num;
        else if (dartResult[i] == '*') {
			res[index] *= 2;
			if (index > 0) res[index - 1] *= 2;
        }
        else if (dartResult[i] == '#')
			res[index] *= -1;
    }
   
    int answer = 0;

	answer = res[0] + res[1] + res[2];

    return answer;
}


int main() {
    string dartResult[] = { "1S2D*3T", "1D2S#10S", "1D2S0T", "1S*2T*3S", "1D#2S*3S", "1T2D3D#", "1D2S3T*59" };
    int expected[] = { 37, 9, 3, 23, 5, -4, 59 };
    for (int i = 0; i < 7; ++i) {
        int result = solution(dartResult[i]);
        if (result == expected[i]) {
            printf("Test case %d passed.\n", i + 1);
        }
        else {
            printf("Test case %d failed. Expected %d but got %d.\n", i + 1, expected[i], result);
        }
    }
	return 0;
}
