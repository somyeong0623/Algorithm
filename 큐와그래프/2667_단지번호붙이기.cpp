//2667번: 단지번호붙이기

/*
지도의 크기 N
5<=N<=25

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n;
queue<pair<int, int>> q;
vector<int> v;
char arr[25][25];
bool visit[25][25];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};


void bfs(int x, int y){
    int cnt=1;
    
    q.push(make_pair(x,y));
    visit[x][y]=true;
    while(!q.empty()){
       int cur_x=q.front().first;
       int cur_y=q.front().second;
       q.pop();

       for(int i=0; i<4; i++){
           int nx=cur_x+dx[i];
           int ny=cur_y+dy[i];

           if(nx<0 || ny<0 || nx>=n || ny>=n) //단지 배열 범위 벗어나면 패스
            continue;

           if(visit[nx][ny]==false && arr[nx][ny]=='1'){
               visit[nx][ny]=true;
               q.push(make_pair(nx,ny));
               cnt++;
           }
       }

    }
    v.push_back(cnt);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           cin>>arr[i][j];
        } 
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j]==false && arr[i][j]=='1'){ //방문하지 않았고, 집이 있는 경우만 BFS 시행
                // cout<<"x: "<<i << ", y:"<<j<<"\n";
                bfs(i,j);
            }
        }
    }

    sort(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"\n";
    }
}