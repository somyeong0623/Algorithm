#include <string>
#include <vector>
#include <algorithm>
//최대 2명까지 탈수 있다는 조건이 있으므로, 가장 이상적인 경우는
//제일 무거운 사람과 제일 가벼운 사람이 함께 타는 경우이다.

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int sum=0;
    sort(people.begin(), people.end()); //오름차순 정렬
    int min_index=0;
    int max_index=people.size()-1;
    
    while(min_index<=max_index){
        answer++; //한번 whilw 돌때마다 구명보트 한번 필요
        if(people[min_index]+people[max_index]<=limit){ //가벼운&무거운 사람이 같이탈수 있으면 인덱스를 각각 증가, 감소시켜서 전체 횟수(answer 세는 횟수)를 2번 줄여주고, 같이탈수 없다면 min쪽만 올리거나 max쪽만 내려서 전체 횟수를 1번 줄여준다.
            min_index++;
            max_index--;
        }else{ 
            // min_index++; //여기서 min_index++ 대신 max_index-- 해야하는 이유? 잘 모르겠 ,,,,큰수 없애는게 더 좋은것 같긴 한데 ,,,,,,, 어차피 1번 줄이는거니까 이왕이면 큰수 없애는 건가 ??
            max_index--;
        }
    }
    
    return answer;
}