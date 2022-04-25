#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    priority_queue<int, vector<int>,greater<int>> pq; //우선순위 큐 오름차순으로 정렬
    int answer=0; //초기값 -1로 설정
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(pq.size()>1 && pq.top()<K){ //pq의 사이즈가 1보다 작거나 우선순위 큐의 맨처음값(작은값)이 K이상이면 종료하고 answer리턴
                int a=pq.top();
                pq.pop();
                int b=pq.top();
                pq.pop();
                int c=a+b*2;
                pq.push(c);
                answer++;
            }
    
    if(pq.top()<K){ // 1개남아서 while문 나왔는데, 이때 하나 값이 K이상을 만족할 수도 있으니 이를 체크해줘야한다. 한개 남은 값이 K보다 작으면 문제 조건을 만족할수 없는 경우이므로 -1리턴
        return -1;
    }else{
    return answer;
    }

}