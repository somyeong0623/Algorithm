//2512.예산
/*
지방의수 3<=N<=10,000
예산요청 정수 1<=v[i]<=100,000
총 예산 N<=M<1,000,000,000 

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer;
int n,m;
vector<int> money;

int sum(int mid){  //mid를 상한액으로 잡았을때, 각 지방에 배정한 돈의 총 합
    int total=0;
    for(int i=0; i<n; i++){
        if(money[i]<mid){
            total+=money[i];
        }else{
            total+=mid;
        }
    }
    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        money.push_back(x);
    }
    cin>>m;
    
    sort(money.begin(),money.end());
    int st=1;
    int en=m;
    int mid=0;

    while(st<=en){
        mid=(st+en)/2;
        if(sum(mid)<=m){ //배정한 금액 총합이 <=m이면 mid를 증가시키는 방향으로
            if(answer<mid){
                answer=mid;
            }
            st=mid+1;

        }else{ //mid를 감소시키는 방향으로
            en=mid-1;
        }
        
    }

    if(answer>money[n-1]){//상한액이 지방 요청금액의 최댓값보다 크면 그 값으로 갱신
        answer=money[n-1]; 
    }
    cout<<answer<<"\n";
}