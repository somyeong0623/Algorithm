//프린터
// 몰라서 구글링함. 다시풀어 보기!!!

#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(vector<int> priorities, int location) {
    int answer=0;
    int cnt=0;
    
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    for(int i=0; i<priorities.size(); i++){
        q.push(make_pair(i,priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int index=q.front().first;
        int value=q.front().second;
        q.pop();
        
        if(value==pq.top()){
            cnt++;
            pq.pop();
            
             if(index==location){
                answer=cnt;
                break;
            }
            
        }else{
            q.push(make_pair(index,value));
        }    
    }
    
    return answer;
}