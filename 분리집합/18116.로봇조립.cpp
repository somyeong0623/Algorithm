//18116. 로봇 조립
/*
명령 갯수 1<=N<=1,000,000
부품 번호 : 1~1,000,000
*/
#include <iostream>
#include <vector>
#define N 1000005
using namespace std;

int n;
vector<int> parent(N);
vector<int> cnt(N,1); //부모의 갯수 벡터, 처음엔 1로 초기화

int getParent(int x){
    if(x==parent[x])
        return x;
    
    return parent[x]=getParent(parent[x]);
}

void unionParent(int x, int y){
    x=getParent(x);
    y=getParent(y);

    if(x==y) //이미 같은 부품이면 cnt 증가시키면 안되니까 함수 끝내기
        return;

    if(x>y){
        parent[x]=y;
        cnt[y]+=cnt[x]; //y가 부모인 부품 갯수 증가
    }
    else{
        parent[y]=x;
        cnt[x]+=cnt[y];
    }
}

int getCnt(int x){
    int p = getParent(x); //여기때문에 계속 틀림!! 그냥 부모가 아니라 루트 부모를 찾아야함.
    
    return cnt[p];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for(int i=0; i<=N; i++){
        parent[i]=i;
    }
    
    for(int i=0; i<n; i++){
        char command;
        cin>>command;

        if(command=='I'){ // x와 y의 부모 합치기
            int x,y;
            cin>>x>>y;
            unionParent(x,y);
        }else{ // command=='Q' , z의 부모를 부모로 가지는 부품갯수 출력
            int z;
            cin>>z;
            cout<<getCnt(z)<<"\n";
        }
    }

    // cout<<"\n";
    // for(int i=1; i<=n; i++){
    //     cout<<cnt[i]<<" ";
    // }


}