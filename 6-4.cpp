#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // Key: 신고당한 사람, Value: 신고한 사람들의 집합 (중복 자동 제거)
    unordered_map<string, unordered_set<string>> reported_by;

    // 각 유저가 결과적으로 받을 메일의 수
    unordered_map<string, int> mail_count;

    // 1. 문자열 파싱 및 신고 기록
    for (const string& r : report) {
        stringstream ss(r);
        string reporter, reported;

        // 공백을 기준으로 분리
        ss >> reporter >> reported;

        // 신고당한 사람의 집합에 신고자를 추가 (set이므로 중복 신고는 무시됨)
        reported_by[reported].insert(reporter);
    }

    // 2. 정지 기준(k) 확인 및 메일 발송 횟수 계산
    for (const auto& pair : reported_by) {
        // 신고당한 횟수가 k번 이상이면
        if (pair.second.size() >= k) {
            // 해당 유저를 신고한 모든 사람의 메일 카운트 증가
            for (const string& reporter : pair.second) {
                mail_count[reporter]++;
            }
        }
    }

    // 3. 주어진 id_list 순서대로 결과 배열 완성
    vector<int> answer;
    for (const string& id : id_list) {
        answer.push_back(mail_count[id]);
    }

    return answer;
}