//1976. 여행가자
/*
도시의 수 N<=2000
여행계획에 속한 도시들의수 M<=1000
N*N 배열 : 연결정보
여행계획 
*/
#include <iostream>
using namespace std;

int n,m;
int parent[201];
bool connect[201][201];
int plan[10001];
string answer="YES";

int getParent(int x){ //루트 부모로 저장
     if(parent[x]==x)
        return x;
    
    return parent[x]=getParent(parent[x]);
}

void unionParent(int x,int y){ //부모 합치기 (더 작은수로)
    x=getParent(x);
    y=getParent(y);

    if(parent[x]==parent[y]) //이미 같은 부모면 패스
        return;

    if(x>y)
        parent[x]=y;
    else
        parent[y]=x;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cin>>m;

    //부모 자기자신으로 초기화
    for(int i=1; i<=n; i++){
        parent[i]=i;
    }

    //연결된 여행지의 부모 union
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>connect[i][j];
            if(connect[i][j]==1){
                unionParent(i,j);
            }
        }
    }

    //여행 계획
    for(int i=1; i<=m; i++){
       cin>>plan[i];
    }

    int temp=plan[1]; // 첫 여행지
    //여행경로 순서대로 돌면서 부모가 같은지 확인
    for(int i=2; i<=m; i++){
        if(getParent(temp)!=getParent(plan[i])){
            answer="NO";
            break;
        }
        temp=plan[i]; //temp 다음 여행지로 갱신
    }
    cout<<answer<<"\n";

}