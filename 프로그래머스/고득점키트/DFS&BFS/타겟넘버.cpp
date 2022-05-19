
/*
풀이 과정
DFS 이용.
numbers 벡터에서 처음 값부터 더하거나 빼는 경우를 선택하여 벡터 끝까지 이 과정을 반복하였을 때,
sum값이 target일때마다 answer++
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>

bool check[20];
int cnt;

using namespace std;
void dfs(vector<int>& numbers, int index,int sum,int target){
    // cout<<"index: "<<index <<", sum: "<<sum<<endl;
    
    if(index==numbers.size()){ //재귀함수 종료 조건
        if(sum==target){
            // cout<<"target입니다"<<endl;
            cnt++;
        }
        return;
    }
        int next=numbers[index];

                    dfs(numbers, index+1, sum+next, target);
                    dfs(numbers,index+1, sum-next,target);

    // }
}


int solution(vector<int> numbers, int target) {
    dfs(numbers,0,0,target); //numbers 벡터, 현재 index, 현재 sum, target
    return cnt;
}