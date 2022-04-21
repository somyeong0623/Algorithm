#include <string>
#include <vector>

using namespace std;
//풀이 방법: prices의 각 원소를 돌면서 떨어지지 않은 기간을 answer에 push한다.

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0; i<prices.size(); i++){
        int cur=prices[i]; //prices의 현재 인덱스
        int cnt=0; //i번째 가격이 떨어지지 않은 기간(초)
        
        for(int j=i+1; j<prices.size(); j++){ //현재 인덱스의 다음 인덱스부터 비교 시작
            cnt++;//일단 더한다. 그 다음 초에 가격이 떨어져도 그 초는 기간에 반영하기 때문에.
            if(cur>prices[j]){ //가격이 떨어졌을 경우, cnt를 push하고 break
                answer.push_back(cnt);
                break;
            }
            if(j==prices.size()-1){ // 끝까지 다 봤을경우 cnt를 push하고 바깥포문을 통해 다음인덱스의 원소로 넘어감.
                answer.push_back(cnt);
            }
        }
    }
    answer.push_back(0); //마지막원소는 무조건 0초 이므로 push
    
    return answer;
}