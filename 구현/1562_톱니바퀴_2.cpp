//15662번: 톱니

/*
톱니바퀴 갯수 1<=T<=1,000
N:0, S:1
회전 횟수 1<= k <= 1,000
1: 시계방향
-1: 반시계방향


K번 히전후 12시방향이 S극인 톱니바퀴 갯수 출력

*/
#include <iostream>
using namespace std;

int T; //톱니바퀴 갯수
int arr[1001][9];// 톱니바퀴 배열
int k; //회전 횟수
int num, direction; //회전시킨 톱니바퀴 번호, 회전 방향


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>t;
    for(int i=1; i<=t; i++){
        for(int j=1; j<=8; j++){
            cin>>arr[i][j];
        }
    }
    cin>>k;
    while(k--){
        cin>>num>>direction;
    }
}