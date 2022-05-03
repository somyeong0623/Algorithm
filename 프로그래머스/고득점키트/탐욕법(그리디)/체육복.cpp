/*
2<=n<=30
*/
#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;
bool have[31]; //체육복 유무, 유:true 무:false


int solution(int n, vector<int> lost, vector<int> reserve) {
    memset(have,true, sizeof(have));
    sort(reserve.begin(), reserve.end());
    int answer = 0;
    
    for(int i=0; i<lost.size(); i++){
        have[lost[i]]=false;
    }
    for(int i=1; i<=n; i++){
        cout<<have[i]<<" ";
    }
    cout<<"\n";
    
    for(int i=0; i<reserve.size(); i++){ //여벌있는 사람이 도난당한 학생인지 먼저 체크. 맞다면 옷 채워주고 reserve벡터에서 삭제
        if(have[reserve[i]]==false){
            have[reserve[i]]=true;
            reserve.erase(reserve.begin()+i);
        }
    }
    
    for(int i=0; i<reserve.size(); i++){
        cout<<"현재 reserve: "<<reserve[i]<<"\n";
        int cur= reserve[i]; //현재 여벌 있는 사람의 번호
        if(have[cur]==false){ 
            have[cur]=true;
            continue;
        }
        if(cur-1>=1){
            if(have[cur-1]==false){
                have[cur-1]=true;
                cout<<cur-1<<"\n";
                continue; //한명에게만 빌려줄 수 있으니까 빌려줬으면 continue
            }
        }
        if(cur+1<=n){
            if(have[cur+1]==false){
                have[cur+1]=true;
                cout<<cur+1<<"\n";
                continue;
                }
            }
        }

    for(int i=1; i<=n; i++){
        if(have[i]==true)
            answer++;
    }
        for(int i=1; i<=n; i++){
        cout<<have[i]<<" ";
    }
   
    
    return answer;
}