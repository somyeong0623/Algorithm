//1717. 집합의 표현/
/*
숫자 1<=N<=1,000,000
연산 갯수 1<=M<=100,000
*/
#include <iostream>
#include <vector>
using namespace std;

int n,m;

//부모 누군지 찾기
int getParent(vector<int> &parent,int x){
    if(parent[x]==x)
        return x;

    return parent[x]=getParent(parent,parent[x]);
}

//x와 y의 부모 합치기 -> 더 작은 수로
void unionParent(vector<int> &parent,int x,int y){
    x=getParent(parent,x);
    y=getParent(parent,y);
    if(x<y)
        parent[y]=x;
    else  
        parent[x]=y;
}

//같은 부모 가지는지 확인
bool sameParent(vector<int> &parent, int x,int y){
    x=getParent(parent,x);
    y=getParent(parent,y);
    if(x==y)
        return 1;
    else
        return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;

    vector<int> parent(n+1,0);

    for(int i=0; i<=n; i++){ //각 부모를 자기자신으로 초기화
        parent[i]=i; 
    }


    for(int i=0; i<m; i++){
        int command, x,y;
        cin>>command>>x>>y;
        
        if(command==0){
            unionParent(parent,x,y);
        }else{ //command==1
            if(sameParent(parent,x,y))
                cout<<"YES"<<"\n";
            else
                cout<<"NO"<<"\n";
        }
    }

}