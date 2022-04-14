//7576번: 토마토

/*
상자크기 가로 M, 세로 N
2<=M,N<=1,000
1 익은토마토
0 익지않은 토마토
-1 안들어있음
*/

#include <iostream>
#include <queue>
using namespace std;
int m,n;
int tomato[1000][1000];
int dist[1000][1000]; //방문체크이자 시작지점으로부터의 거리를 나타낸다
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

queue<pair<int,int>> q;
int answer;

void bfs(){
    for(int i=0; i<n; i++){ //j가 열 인덱스, i가 행 인덱스
        for(int j=0; j<m; j++){
            if(tomato[i][j]==1){
                q.push(make_pair(i,j));//(열인덱스,행인덱스) 순서로 푸쉬
                dist[i][j]=0;
            }
        }
    }

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;

        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

 
            if(nx >= 0 && ny >= 0 && nx < n && ny < m){

                if(tomato[nx][ny]==0 && dist[nx][ny]==-1){
                    dist[nx][ny]=dist[cx][cy]+1;
                    tomato[nx][ny]=1;
                    q.push(make_pair(nx,ny));

                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>n; //m이 가로, n이 세로
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tomato[i][j];
            dist[i][j]=-1; // 방문안한 좌표 -1로 초기화
        }
    }
    bfs();

    answer=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(tomato[i][j]==0){ //bfs끝났는데 안익은 토마토 있으면 -1출력하고 종료
                cout<<-1<<"\n";
                return 0;
            }

            if(answer<dist[i][j])
                answer=dist[i][j]; //  최댓값 찾기
        }
    }
    
    cout<<answer<<"\n";
}