#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 1. 모든 학생의 체육복 개수를 1로 초기화 (1번~n번 사용을 위해 n+1 크기)
    vector<int> student(n + 1, 1);

    // 2. 도난당한 학생은 -1
    for (int l : lost) student[l]--;

    // 3. 여벌이 있는 학생은 +1
    // (여기서 도난당한 학생이 여벌이 있으면 자동으로 1이 됨)
    for (int r : reserve) student[r]++;

    // 4. 체육복이 없는 학생(0)을 찾아 빌려주기
    for (int i = 1; i <= n; i++) {
        if (student[i] == 0) {
            // 앞번호 학생이 여벌이 있는지 확인
            if (i > 1 && student[i - 1] == 2) {
                student[i - 1] = 1;
                student[i] = 1;
            }
            // 뒷번호 학생이 여벌이 있는지 확인
            else if (i < n && student[i + 1] == 2) {
                student[i + 1] = 1;
                student[i] = 1;
            }
        }
    }

    // 5. 체육복이 1벌 이상인 학생 수 세기
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (student[i] >= 1) answer++;
    }

    return answer;
}