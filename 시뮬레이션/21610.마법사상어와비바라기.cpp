//21610.마법사 상어와 비바라기
/*
배열 크기 2<=N<=50
명령 횟수 1<=M<=100
물의 양 0<=A[r][c]<=100
방향 1<=di<=8
이동하는 칸 수 1<=si<=50

*/
#include <iostream>
using namespace std;
int n,m,d,s;
int water[51][51];

bool cloud_copy[51][51]; //처음 구름 위치정보
bool cloud[51][51]; //d방향으로 s칸 이동한 구름정보

//네개의 대각선 좌표 
//왼쪽위 대각선, 오른쪽위 대각선, 왼쪽아래 대각선, 오른쪽아래 대각선
int dy[]={-1,-1,1,1}; //행
int dx[]={-1,1,-1,1}; //열
int answer;//정답

void copyCloud(){ //cloud_copy에 cloud정보 복사
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cloud_copy[i][j]=cloud[i][j];
        }
    }
}

void initCloud(){ //cloud[][] 0으로 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cloud[i][j]=0;
        }
    }
}

void moveCloud(int d,int s){//구름 이동
    s=s%n; //이거 안해서 짱 헤맴...
    if(d==1){ //왼쪽
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cloud_copy[i][j]==true){
                        cloud[i][(j+n-s)%n]=true;
                        cloud_copy[i][j]=false;
                    }
                }
            }
        }else if(d==2){//왼쪽 위 대각선
             for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cloud_copy[i][j]==true){
                        cloud[(i+n-s)%n][(j+n-s)%n]=true;
                        cloud_copy[i][j]=false;
                    }
                }
            }
        }else if(d==3){ //위
              for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cloud_copy[i][j]==true){
                        cloud[(i+n-s)%n][j]=true;
                        cloud_copy[i][j]=false;
                    }
                }
            }
        }else if(d==4){ //오른쪽 위 대각선
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cloud_copy[i][j]==true){
                        cloud[(i+n-s)%n][(j+n+s)%n]=true;
                        cloud_copy[i][j]=false;
                    }
                }
            }
        }else if(d==5){//오른쪽
             for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cloud_copy[i][j]==true){
                        cloud[i][(j+n+s)%n]=true;
                        cloud_copy[i][j]=false;
                    }
                }
            }
        }else if(d==6){//오른쪽 아래 대각선
              for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cloud_copy[i][j]==true){
                        cloud[(i+n+s)%n][(j+n+s)%n]=true;
                        cloud_copy[i][j]=false;
                    }
                }
            }
            
        }else if(d==7){// 아래
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cloud_copy[i][j]==true){
                        cloud[(i+n+s)%n][j]=true;
                        cloud_copy[i][j]=false;
                    }
                }
            }

        }else{// 8: 왼쪽 아래 대각선
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cloud_copy[i][j]==true){
                        cloud[(i+n+s)%n][(j+n-s)%n]=true;
                        cloud_copy[i][j]=false;
                    }
                }
            }
        }
}
void addWater(){ //구름이 있는칸의 물의 양 1증가
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cloud[i][j]==true){
                water[i][j]++;
            }
        }
    }
}
void copyWater(){ //물복사 마법
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cloud[i][j]==true){
                int cnt=0;
                int cy=i;
                int cx=j;
                for(int d=0; d<4; d++){
                   int ny=cy+dy[d];
                   int nx=cx+dx[d];

                    if(ny>=0 && ny<n&& nx>=0 && nx<n){
                        if(water[ny][nx]){
                        cnt++;
                        }
                    }
                }
                water[i][j]+=cnt;    
            }
        }   
    }

}
void makeCloudAndRemoveWater(){ //5번 과정
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cloud_copy[i][j]==true){ //기존에 구름있던칸 제외
                continue;
            }
            if(water[i][j]>=2){
                cloud[i][j]=true;
                water[i][j]-=2;
            }
        }
    }
}

void printWater(){ //물 상태 출력
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<water[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printCloud(){ //구름 상태 출력
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<cloud[i][j]<<" ";
        }
        cout<<endl;
    }
}
void printCloudCopy(){ //구름 복사 상태 출력
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<cloud_copy[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>water[i][j];
        }
    }
    //처음 비구름
    cloud[n-1][0]=true; cloud[n-1][1]=true;
    cloud[n-2][0]=true; cloud[n-2][1]=true;
    copyCloud(); //cloud_copy에 cloud정보 담아놓기
    initCloud(); //cloud 0으로 초기화


    for(int i=0; i<m; i++){

        cin>>d>>s;
       
        moveCloud(d,s); //1. 구름이 d방향으로 s만큼 이동
        addWater(); //2. 구름이 있는칸에 물의 양 1 증가
        copyWater(); //4. 2번에서 구름이 있었던 칸에 물복사 마법 시전.
        copyCloud(); //copy_cloud에 구름정보 저장.
        initCloud(); //3. 구름 모두 사라짐       
        makeCloudAndRemoveWater(); // //5. 3.구름이 있던칸을 제외하고, 물의 양이 2이상인 모든칸에 구름이 생기고, 물의 양이 2 줄어듦.

        //이 두줄은 구름이동전에 해줘야하는 함수
        copyCloud(); //copy배열에 구름상태 복사
        initCloud(); //구름 초기화

    }
    //물의 양 합 구하기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            answer+=water[i][j];
        }
    }

    cout<<answer<<"\n";
}