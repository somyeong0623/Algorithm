//7569번. 토마토
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int m,n,h; //열, 행, 높이
int tomato[101][101][101];
int dist[101][101][101];//거리
int answer;
int dh[6]={0,0,0,0,-1,1};//높이
int dr[6]={-1,1,0,0,0,0};//행
int dc[6]={0,0,-1,1,0,0};//열
queue<pair<int,pair<int,int>>> q;//높이, 행, 열

void bfs(){//높이, 행, 열
    
    
    while(!q.empty()){
        int cur_h=q.front().first; //높이
        int cur_r=q.front().second.first;//행
        int cur_c=q.front().second.second;//열
        q.pop();
        cout<<cur_h<<" "<<cur_r<<" "<<cur_c<<endl;
       

        for(int i=0; i<6; i++){
            int next_h=cur_h+dh[i];
            int next_r=cur_r+dr[i];
            int next_c=cur_c+dc[i];

            if(next_h<0 || next_h>=h || next_r<0 || next_r>=n || next_c<0 || next_c>=m){
                continue;
            }
            if(dist[next_h][next_r][next_c]>=0){
                continue;
            }
            dist[next_h][next_r][next_c]=dist[cur_h][cur_r][cur_c]+1;     
            q.push({next_h,{next_r,next_c}});

            // if(next_h>=0 && next_h<h && next_r>=0 && next_r<n &&next_c>=0 && next_c<m){
            //     if(dist[next_h][next_r][next_c]>=0){
            //         continue;
            //     }
            //         dist[next_h][next_r][next_c]=dist[cur_h][cur_r][cur_c]+1;     
            //         q.push({next_h,{next_r,next_c}});
            // }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>n>>h; //열 갯수, 행갯수, 높이

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){ //행
            for(int k=0; k<m; k++){ //열
                cin>>tomato[i][j][k];
                if(tomato[i][j][k]==1){
                    q.push({i,{j,k}});
                    dist[i][j][k]=0;
                }else if(tomato[i][j][k]==0){
                    dist[i][j][k]=-1;
                }else{ //tomato[i][j][k]==-1;
                    dist[i][j][k]=0;
               }
            }
        }
    }
    bfs();

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; j++){
                if(dist[i][j][k]==-1){
                    cout<<-1<<"\n";
                    return 0;
                }

                if(answer<dist[i][j][k]){
                    answer=dist[i][j][k];
                }
            }
        }
    }
    cout<<answer<<"\n";

    
}