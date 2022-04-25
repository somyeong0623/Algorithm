/*
2<= n,m <= 100
1<= r <=1,000
n,m은 짝수

주의할점
R이 2이상이면, 이전 결과의 배열에서 이어서 command명령 실행해야함
*/


#include <iostream>
using namespace std;

int n,m,r;
int arr[100][100]; //최종 출력할 배열
int arr2[100][100];//입력받은 배열을 복사해둔 배열
int command;

int main(){
    cin>>n>>m>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];

        }  
    }

    //배열 복사
    for(int t=0; t<r; t++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr2[i][j]=arr[i][j];
            }
        }

        cin>>command; //명령 입력

        if(command==1){ // 상하 반전
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j]=arr2[n-1-i][j];
                }
            }

        }else if(command==2){ // 좌우 반전
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j]=arr2[i][m-1-j];
                }
            }

        }else if(command==3){ //오른쪽으로 90도 회전
            int temp = n; //4,5번의 명령인 경우 행,열 길이가 서로 바뀌므로 바꿔줘야함.
            n=m;
            m=temp;

            for(int i=0; i<n ; i++){
                for(int j=0; j<m; j++){
                    arr[i][j]=arr2[m-1-j][i];
                }
            }
      
        }else if(command==4)ㅌ{ //왼쪽으로 90도 회전
             int temp = n;
            n=m;
            m=temp;

            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j]=arr2[j][n-1-i];
                }
            }
        }else if(command==5){
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){

                    //arr2(복사배열 기준으로함)
                    if(i<n/2 && j<m/2 ){//1번 그룹이면 -> 2번그룹으로
                        arr[i][j+m/2]=arr2[i][j];
                    }else if(i<n/2 && j>=m/2){ //2번이면 -> 3번으로
                        arr[i+n/2][j]=arr2[i][j];
                    }else if(i>=n/2 && j>=m/2 ){//3번이면 -> 4번으로
                        arr[i][j-m/2]=arr2[i][j];
                    }else if(i>=n/2 && j<m/2)//4번이면 -> 1번으로
                        arr[i-n/2][j]=arr2[i][j];
                    }
                }
            
        }else{ //6번 명령
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){

                    //arr2(복사배열 기준으로함)
                    if(i<n/2 && j<m/2 ){//1번 그룹이면 -> 4번그룹으로
                        arr[i+n/2][j]=arr2[i][j];
                    }else if(i<n/2 && j>=m/2){ //2번이면 -> 1번으로
                        arr[i][j-m/2]=arr2[i][j];
                    }else if(i>=n/2 && j>=m/2 ){//3번이면 -> 2번으로
                        arr[i-n/2][j]=arr2[i][j];
                    }else if(i>=n/2 && j<m/2){//4번이면 -> 3번으로
                        arr[i][j+m/2]=arr2[i][j];
                    }
                }
            }
        }
    } 
     for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
}  