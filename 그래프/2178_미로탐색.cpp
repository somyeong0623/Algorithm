//2178번: 미로탐색

/*

2<=N,M,M=<=100

*/

#include <iostream>
#include <queue>
using namespace std;
int n,m;
char arr[100][100];
int answer[100][100];
bool visit[100][100];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

queue<pair<int,int>> q;

void bfs(int x,int y){  
    answer[x][y]=1;
    visit[x][y]=true;
    q.push(make_pair(x,y));

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        // cout<<"cx : "<<cx<<", cy: "<<cy<<"\n";
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;
            
            if(arr[nx][ny]=='1' && visit[nx][ny]==false){
                answer[nx][ny]=answer[cx][cy]+1;
                q.push(make_pair(nx,ny));
                visit[nx][ny]=true;
            }
        }

    }

}


int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    bfs(0,0);
    cout<<answer[n-1][m-1]<<"\n";


}