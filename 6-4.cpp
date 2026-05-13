//#include <string>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//    // 사람 이름 신고한 사람 맵
//    // 사람 이름 신고 당한 횟수
//    unordered_map<string, int> badIDs;
//    unordered_map<string, string> whotowho;
//
//    for (auto& id : id_list) {
//		badIDs[id] = 0;
//    }
//    for (auto& r : report) {
//        string reporter;
//        string reported;
//        while (r << reporter) {
//
//        }
//    }
//    
//
//    vector<int> answer;
//    return answer;
//}

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 1. 신고 기록용 해시 맵 (핵심 자료구조)
    // Key: 신고당한 사람, Value: 신고한 사람들의 집합 (중복 자동 제거)
    unordered_map<string, unordered_set<string>> reported_by;

    // 2. 메일 발송 횟수 카운트용 맵
    // Key: 메일 받을 사람, Value: 받을 메일 개수
    unordered_map<string, int> mail_count;

    // 3. report 배열 파싱 및 기록
    for (const string& r : report) {
        stringstream ss(r);
        string reporter, reported;
        ss >> reporter >> reported; // 공백을 기준으로 신고자, 피신고자 분리

        // 피신고자를 키로 하여, 신고자 목록(Set)에 신고자 이름 추가
        reported_by[reported].insert(reporter);
    }

    // 4. k번 이상 신고당한 사람 찾아서 메일 발송 카운트 증가
    for (const auto& pair : reported_by) {
        // pair.first: 신고당한 사람, pair.second: 신고한 사람들의 집합
        if (pair.second.size() >= k) {
            // 정지 기준 k번 이상이라면, 신고한 사람들 전원에게 메일 1개씩 예약
            for (const string& reporter : pair.second) {
                mail_count[reporter]++;
            }
        }
    }

    // 5. id_list에 담긴 순서대로 최종 결과 배열 완성
    vector<int> answer;
    for (const string& id : id_list) {
        answer.push_back(mail_count[id]);
    }

    return answer;
}