//1260번. DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m,start;
vector<int> v[1001];
queue<int> q;
bool check[1001];

void dfs(int x){
    check[x]=true;
    cout<<x<<" ";
    for(int i=0; i<v[x].size(); i++){
        int y=v[x][i];
        if(check[y]==false){
            dfs(y);
        }
    }

}

void bfs(int x){
    q.push(x);
    check[x]=true;
    while(!q.empty()){
        int y=q.front();
        cout<<y<<" ";
        q.pop();
        for(int i=0; i<v[y].size(); i++){
            int a=v[y][i];
            if(check[a]==false)
                q.push(a);
                check[a]=true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>start;
    for(int i=0; i<m; i++){
        int from, to;
        cin>>from>>to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    
    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }

    dfs(start);

    cout<<"\n";
    memset(check,false,sizeof(check));

    bfs(start);


}