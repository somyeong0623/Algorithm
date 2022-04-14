//7562번: 나이트의 이동
/*

입력
테스트케이스

체스판 길이 I  (4<=I<=300)
현재 좌표
도착 좌표

*/
#include <iostream>
#include <queue>

using namespace std;

int t,n;
// 나이트가 갈수있는 8개의 좌표를 배열로 표기
int dx[]={-1,-2,-2,-1,1,2,2,1};
int dy[]={-2,-1, 1,2,-2,-1,1,2};
int visit[300][300];

void bfs(int cur_x, int cur_y){
    queue<pair<int,int>> q;

    visit[cur_x][cur_y]=0;
    q.push(make_pair(cur_x, cur_y));

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop(); 

        for(int i=0; i<8; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<n){
                if(visit[nx][ny]==-1){
                visit[nx][ny]=visit[x][y]+1;
                q.push(make_pair(nx,ny));
                }
            }
        }

    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int i=0; i<t; i++){

        cin>>n;

        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                visit[j][k]=-1;
            }
        }
        int cur_x,cur_y,end_x,end_y;
        cin>>cur_x>>cur_y;
        cin>>end_x>>end_y;
        bfs(cur_x, cur_y);

        cout<<visit[end_x][end_y]<<"\n";
    }

}


