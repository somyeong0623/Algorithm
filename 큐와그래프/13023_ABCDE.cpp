//13023번_ABCDE
#include <iostream>
#include <vector>

using namespace std;

bool arr[2000][2000]; //인접 행렬
vector<int> v[2000]; //인접 리스트
vector<pair<int,int>> edges; // 간선 리스트

int n,m;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        arr[x][y]=arr[y][x]=true;
        edges.push_back({x,y});
        edges.push_back({y,x});
    }
    
    for(int i=0; i<2*m; i++){
        for(int j=0; j<2*m; j++){
            //A->B
            int A=edges[i].first;
            int B=edges[i].second;

            //C->D
            int C=edges[j].first;
            int D=edges[j].second;

            if(A==B||A==C||A==D||B==C||B==D||C==D)
                continue;

            //B->C 확인
            if(arr[B][C]==false)
                continue;

            //D->E인 E 있는지 확인
            for(int E: v[D]){
                if(A==E || B==E || C==E || D==E){
                    
                    continue;
                }

                  cout<<1<<"\n";
                  return 0;
            }
        }
    }
    cout<<0<<"\n";

}

// 문제 이해를 잘못했었음
// 모든 사람이 친구여야 하는줄 알았는데 N명 중에서 임의의 A,B,C,D,E만 문제의 친구조건을 만족하면 되는 문제였다.
// 위 코드는 인접 행렬, 인접 리스트, 간선 리스트를 전부 사용해보는 코드
// 꼭 이렇게 풀어야되는지는 모르겠지만, 일단 풀이방법 이해하고 넘어가자!

/*
풀이 방법

A->B, C->D를 만족하는 A,B,C,D를 먼저 찾고 (간선 리스트)
B->C 인지 확인 (인접 행렬)
그리고 나서 v[D]에서 D->E인 E가 존재하는지 확인 (인접 리스트)


*/ 

