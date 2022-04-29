//14499번: 주사위 굴리기
// 지도 좌표: r:행,  c:열

/*
지도의 각 칸에는 정수가 하나씩 쓰여져 있다. 
주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다. 
0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 
칸에 쓰여 있는 수는 0이 된다.


첫째 줄에 지도의 세로 크기 N, 가로 크기 M (1 ≤ N, M ≤ 20),
 주사위를 놓은 곳의 좌표 x, y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1), 
 그리고 명령의 개수 K (1 ≤ K ≤ 1,000)가 주어진다.

 둘째 줄부터 N개의 줄에 지도에 쓰여 있는 수가 북쪽부터 남쪽으로,
각 줄은 서쪽부터 동쪽 순서대로 주어진다. 
주사위를 놓은 칸에 쓰여 있는 수는 항상 0이다. 
지도의 각 칸에 쓰여 있는 수는 10 미만의 자연수 또는 0이다.

마지막 줄에는 이동하는 명령이 순서대로 주어진다.
 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다.


와 너무어렵다 진짜 .......진짜 ......풀이보고 품....
*/
#include <iostream>
using namespace std;

int dice[7];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int arr[20][20];
int n,m,x,y,k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>x>>y>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    while(k--){ 
        int l;
        cin>>l;
        l-=1;
        
        int nx, ny;
        nx= x+dx[l];
        ny= y+dy[l];

        //바깥으로 이동하는경우, 해당 명령 무시
        if(nx<0 || nx>=n || ny<0 || ny>=m){
            continue;
        }
        
        //주사위 굴리기
        if(l==0){ //right 동쪽
        int temp=dice[1];
        dice[1]=dice[4];
        dice[4]=dice[6];
        dice[6]=dice[3];
        dice[3]=temp;


        }else if(l==1){// left 서쪽
        int temp=dice[1];
        dice[1]=dice[3];
        dice[3]=dice[6];
        dice[6]=dice[4];
        dice[4]=temp;

        }else if(l==2){ //up 북쪽
        int temp=dice[1];
        dice[1]=dice[5];
        dice[5]=dice[6];
        dice[6]=dice[2];
        dice[2]=temp;

        }else{ //down 남쪽
        int temp=dice[1];
        dice[1]=dice[2];
        dice[2]=dice[6];
        dice[6]=dice[5];
        dice[5]=temp;

        }
        x=nx;
        x=ny;

        if(arr[x][y]==0){
            //주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사됨
            arr[x][y]=dice[6];
        }else{
            //0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
            dice[6]=arr[x][y];
            arr[x][y]=0;
        }
    //윗면 출력 : dice[1]
    cout<<x<<" "<<y<<"\n";
    cout<<dice[1]<<"\n";
 
    }

}