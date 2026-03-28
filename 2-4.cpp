#include <iostream>
#include <vector>

using namespace std;

struct Food {
    int t, d, g;
};

// 기준치 정보
int limitT, limitD, limitG, limitCal;

// 조건에 맞는지 확인하는 함수
bool isBalanced(int sumT, int sumD, int sumG) {
    int sumCal = (sumT * 4) + (sumD * 4) + (sumG * 9);

    return (sumT <= limitT &&
        sumD >= limitD &&
        sumG <= limitG &&
        sumCal <= limitCal);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<Food> foods(n);
    for (int i = 0; i < n; i++) {
        cin >> foods[i].t >> foods[i].d >> foods[i].g;
    }

    cin >> limitT >> limitD >> limitG >> limitCal;

    int count = 0;

    // 1. 음식을 1개 선택하는 경우
    for (int i = 0; i < n; i++) {
        if (isBalanced(foods[i].t, foods[i].d, foods[i].g)) {
            count++;
        }
    }

    // 2. 음식을 2개 선택하는 경우
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isBalanced(foods[i].t + foods[j].t,
                foods[i].d + foods[j].d,
                foods[i].g + foods[j].g)) {
                count++;
            }
        }
    }

    // 3. 음식을 3개 선택하는 경우
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (isBalanced(foods[i].t + foods[j].t + foods[k].t,
                    foods[i].d + foods[j].d + foods[k].d,
                    foods[i].g + foods[j].g + foods[k].g)) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}