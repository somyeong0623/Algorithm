#include <string>
#include <vector>
#include <iostream>

using namespace std;
int cnt1, cnt2, cnt3;

//수포자들의 찍는 패턴 초기화
vector<int> v1= {1,2,3,4,5}; //size:5
vector<int> v2={2,1,2,3,2,4,2,5}; //size:8
vector<int> v3={3,3,1,1,2,2,4,4,5,5};//size:10
int max_cnt=0;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for(int i=0;i<answers.size(); i++){
     
        
        // 맞힌 문제 카운트
        if(v1[i%v1.size()]==answers[i])
            cnt1++;
        if(v2[i%v2.size()]==answers[i])
            cnt2++;
        if(v3[i%v3.size()]==answers[i])
            cnt3++;
    }
        
        //최댓값 찾기
        if(max_cnt<cnt1)
            max_cnt=cnt1;
        if(max_cnt<cnt2)
            max_cnt=cnt2;
        if(max_cnt<cnt3)
            max_cnt=cnt3;
    
        cout<<"영인 하이"<<"\n";
        //1번사람부터 확인하면 알아서 오름차순으로 들어간다.
        if(cnt1==max_cnt)
            answer.push_back(1);
        if(cnt2==max_cnt)
            answer.push_back(2);
        if(cnt3==max_cnt)
            answer.push_back(3);
    return answer;
}