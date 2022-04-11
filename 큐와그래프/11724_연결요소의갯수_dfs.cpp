//11724번: 연결 요소의 개수

/*
정점갯수 N, 간선 갯수 M
1<=N<=1,000
0<=M<=N(N-1)/2

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;
vector<int> vec[10001];
bool check[1001];
int answer;

void dfs(int x){
    check[x]=true;
    
    for(int i=0;i<vec[x].size(); i++ ){
        int y=vec[x][i];
        if(check[y]==false){
            dfs(y);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(check[i]==false){
            answer++;
            dfs(i);
        }
      

    }

    cout<<answer<<"\n";
}