//18116. 로봇 조립
/*
명령 갯수 1<=N<=1,000,000
부품 번호 : 1~1,000,000
*/
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> parent(1000001);
vector<int> cnt(1000001,1); //부모의 갯수 벡터, 처음엔 1로 초기화

int getParent(int x){
    if(x==parent[x])
        return x;
    
    return parent[x]=getParent(parent[x]);
}

void unionParent(int x, int y){
    x=getParent(x);
    y=getParent(y);

    if(x>y){
        parent[x]=y;
        cnt[y]++; //y가 부모인 부품 갯수 증가
    }
    else{
        parent[y]=x;
        cnt[x]++; //x가 부모인 부품 갯수 증가
    }
}

int getCnt(int x){
    int p = parent[x];
    
    return cnt[p];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for(int i=0; i<1000001; i++){
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


}