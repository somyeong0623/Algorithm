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
int arr[51][51];
bool cloud[51][51];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    //처음 비구름
    cloud[n-1][0]=true; cloud[n-1][1]=true;
    cloud[n-2][0]=true; cloud[n-2][1]=true;

     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<cloud[i][j]<<" ";
        }

        cout<<endl;
    }
    cout<<"이동후 "<<"\n";

    for(int i=0; i<m; i++){
        cin>>d>>s;
        if(d==1){ //왼쪽
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cloud[i][j]==true){
                        cout<<i<<" "<<j <<"\n";
                        cout<< i<< " "<<(j+n-s)%n<<"\n";
                        cloud[i][(j+n-s)%n]=true;
                        cloud[i][j]=false;
                    }
                }
            }
        }
        // }else if(d==2){//왼쪽 위 대각선
        //      for(int i=0; i<n; i++){
        //         for(int j=0; j<n; j++){
        //             if(cloud[i][j]==true){
        //                 cloud[(i+n-s)%n][(j+n-s)%n]=true;
        //                 cloud[i][j]=false;
        //             }
        //         }
        //     }

        // }

    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<cloud[i][j]<<" ";
        }

        cout<<endl;
    }
}