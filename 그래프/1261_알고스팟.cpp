//1261번: 알고스팟
/*
가로 M
세로 N
1<= N,M <=100
*/

#include <iostream>
#include <queue>
using namespace std;

int n,m;
char arr[101][101];
int dist[101][101];
queue<pair<int,int>> q;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};


void bfs(){
    dist[1][1]=0;
    q.push(make_pair(1,1));

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        for(int i=0 ; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>=1 && ny>=1 && nx<=n && ny<=m ){
                if(dist[nx][ny]==-1){
                    if(arr[nx][ny]=='1'){ //벽일때
                        dist[nx][ny]=dist[cx][cy]+1;
                    }else{ //빈방일때
                        dist[nx][ny]=dist[cx][cy];
                    }

                    q.push(make_pair(nx,ny));

                }else{ //처음 방문이 아니면 최솟값 으로 넣기
                    if(arr[nx][ny]=='1'){ //벽일때
                        if(dist[nx][ny]>dist[cx][cy]+1){
                        dist[nx][ny]=dist[cx][cy]+1;
                        q.push(make_pair(nx,ny));
                        }
                        
                    }else{ //빈방일때
                        if(dist[nx][ny]>dist[cx][cy]){
                        dist[nx][ny]=dist[cx][cy];
                        q.push(make_pair(nx,ny));
                        }
                    }

                }
            }

        }

    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>n;
    for(int i=1;i <=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }

       for(int i=1;i <=n; i++){
        for(int j=1; j<=m; j++){
            dist[i][j]=-1;
        }
    }

    bfs();
    for(int i=1;i <=n; i++){
        for(int j=1; j<=m; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"---------"<<"\n";
    cout<<dist[n][m]<<"\n";
}