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

void moveCloud(int d,int s){//구름 이동
    if(d==1){ //왼쪽
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cloud_copy[i][j]==true){
                        // cout<<i<<" "<<j <<"\n";
                        // cout<< i<< " "<<(j+n-s)%n<<"\n";
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

void printCloud(){ //구름 상태 출력
    cout<<"=====구름 상태====="<<"\n";
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<cloud[i][j]<<" ";
        }

        cout<<endl;
    }
    cout<<"====구름 상태 끝====="<<"\n";
}
void printCloudCopy(){ //구름 상태 출력
    cout<<"=====구름 상태====="<<"\n";
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<cloud_copy[i][j]<<" ";
        }

        cout<<endl;
    }
    cout<<"====구름 상태 끝====="<<"\n";
}

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

  
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<cloud_copy[i][j]<<" ";
        }

        cout<<endl;
    }
    cout<<"이동후 "<<"\n";

    for(int i=0; i<m; i++){
        cout<<"======="<<i+1<<"번째 시작=======\n";
        cin>>d>>s;
        cout<<"처음 구름 상태 "<<"\n";
        printCloudCopy();
       
        moveCloud(d,s); //1. 구름이 d방향으로 s만큼 이동
        cout<<"이동 후 구름 상태"<<"\n";
        printCloud();
    }
}