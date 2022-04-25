#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h_index=0;
    int cnt=0;
    for(int i=1; i<=citations.size(); i++){
        h_index=i; //현재 h-index가 되는지 알아보고자 하는 값
        // cout<<"h_index: "<<h_index<<"\n";
        cnt=0;// h_index번 이상 인용된 논문 갯수, cnt에 포함지지 않은값들은 자동으로 h번 미만 인용되었다는 뜻.
        // 문제에서 이상&이하 같이써도 되나..? 이상&미만 아닌가 ... 헷갈 ..
        
        for(int j=0; j<citations.size(); j++){
            if(citations[j]>=h_index){
                cnt++;
            }

        }
            // cout<< "cnt: "<<cnt<<"\n";
        
        if(h_index<=cnt){ //cnt값이 h_index보다 클때의 최댓값 구하기
            if(answer<h_index){
                answer=h_index;
            }
        }
    }
    
    return answer;
}