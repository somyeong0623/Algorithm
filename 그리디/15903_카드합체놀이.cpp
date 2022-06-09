//15903. 카드 합체 놀이
/* 풀이
카드 중 가장 작은값 두개를 합쳐 나가는것이 점수를 가장 작게 만드는 방법이다.
처음 생각한 방법은 벡터로 입력받아서, '정렬하고 합치는 과정'을 m번 반복하여 마지막에 모든 카드를 더해주는 방법이었다.
하지만 매번 정렬해야하는데 시간이 쓰이므로, 오름차순 정렬되는 우선순위큐를 선언하여 여기에 수를 넣고, 가장 작은 두값을 합치는 방법으로 
풀어서 수행시간을 줄일 수 있다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
long long answer;
long long sum;
priority_queue <long long, vector<long long>, greater<long long>> pq; //오름차순

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        pq.push(x);
    }

    for(int i=0; i<m; i++){
        sum=pq.top();
        pq.pop();
        sum+=pq.top();
        pq.pop();
        pq.push(sum);
        pq.push(sum);

    }

    while(!pq.empty()){
        answer+=pq.top();
        pq.pop();
    }


    cout<<answer<<"\n";

}