//15685.드래곤커브 (몰라서 구글참고)
/*
드래곤 커브갯수 1<=N<=20
드래곤 커브정보 x,y,d,g (시작점 x, 시작점 y, 시작 방향, 세대)
0<=x,y<=100 0<=d<=3 0<=g<=10
방향
0: ->
1: 위로
2: <-
3: 아래로

1x1 정사각형 중 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수 출력

*/
#include <iostream>
#include <vector>
using namespace std;

int n;
int x,y,d,g;
// x가 가로, y가 세로인것 주의 -> x가 세로, y가 가로로 바꿈
// 0,1,2,3 오른쪽,위쪽,왼쪽,아래쪽
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
vector<int> curve; //커브 방향정보 저장
bool arr[101][101]; //커브 좌표, 길이 1짜리 커브(막대기) 시작점에 놓여있으면 true
int answer; //정답
int end_x, end_y; //커브의(막대기의) 끝점 
int dir; //방향

void generation(){ //세대 수 만큼 커브만들기

    // 다음 세대 만드는 법
    // 이전 세대 커브정보를 끝에서 부터 꺼낸다음, 방향은 이전 방향+1 인 방향이다.

    int curve_size=curve.size(); //인트로 미리 빼놔야 새로 push할때 사이즈 안변한다.
    for(int i=curve_size-1; i>=0; i--){
        int next_dir=(curve[i]+1)%4;
        // cout<<"next_dir: "<<next_dir<<"\n";

        end_x=end_x+dx[next_dir];
        end_y=end_y+dy[next_dir];

        //다음 커브(다음 막대기)의 시작점 체크
        arr[end_x][end_y]=true;
        // cout<<"end_x: "<<end_x<<",end_y :"<<end_y<<"\n";

        //방향정보 넣기
        curve.push_back(next_dir);


    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>y>>x>>d>>g; //x가 세로, y가 가로로 바꿈
        
        //각 커브 정보 주어질때, 커브벡터 초기화
        curve.clear();
        //시작점
        arr[x][y]=true;
        // cout<<"x: "<<x<<",y :"<<y<<"\n";

        //0세대 끝점
        end_x=x+dx[d];
        end_y=y+dy[d];

        //0세데 만든이후의 끝점 표시
        arr[end_x][end_y]=true;
        // cout<<"end_x: "<<end_x<<",end_y :"<<end_y<<"\n";

        //0세대 방향정보
        curve.push_back(d);

        for(int i=0; i<g; i++){
            generation();
        }


    }
    // cout<<endl;
    //     for(int i=0; i<10; i++){
    //         for(int j=0; j<10; j++){
    //             cout<<arr[i][j];
    //         }
    //         cout<<"\n";
    //     }

    for(int i=0; i<100; i++){ //0~99
        for(int j=0; j<100; j++){ //0~99
            if(arr[i][j]==true && arr[i][j+1]==true && arr[i+1][j]==true && arr[i+1][j+1]){
                answer++;
            }
        }
    }
    
    cout<<answer<<"\n";
}