//9079. 동전게임 (몰라서 구글링)
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int tc;
int arr[3][3];
bool visit[512]; //0000000~1111111 -> 0~511

//행 뒤집기
void flipRow(int row){
    for(int i=0; i<3; i++){
        arr[row][i]=arr[row][i]^1; //XOR 연산자 -> 토글
    }
}

//열 뒤집기
void flipCol(int col){
    for(int i=0; i<3; i++){
        arr[i][col]=arr[i][col]^1;
    }
}

//대각선 뒤집기
void flipCross(int cross){ //6,7인 경우
    if(cross==6){ //왼쪽위-오른쪽아래 방향 대각선
        for(int i=0; i<3; i++){
            arr[i][i]=arr[i][i]^1; 
        }
    }else{ //왼쪽아래-오른쪽위 방향 대각선
        for(int i=0; i<3; i++){
            arr[2-i][i]=arr[2-i][i]^1;
        }
    }
}
int makeNum(){//배열상태를 10진법으로 저장
    int num=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            num=num*2+arr[i][j];
        }
    }
    return num;
}

void makeArr(int num){ //10진법을 바탕으로 배열 만들기
    for(int i=2; i>=0; i--){ //배열 끝에서부터 채우기
        for(int j=2; j>=0; j--){
            arr[i][j]=num%2;
            num/=2;
        }
    }
}

bool checkSame(){
    int num=makeNum();
    if(num==0 || num==511){ //모두같은면이면 10진법으로 0또는 511임.
        return true;
    }else{
        return false;
    }
}


int bfs(int now_num, bool visit[]){ //최소 횟수 출력 (불가능한경우 -1)
    queue<pair<int,int>> q;//first:현재상태, second:횟수
    q.push({now_num,0});

    while(!q.empty()){
        int now_num=q.front().first;
        int cnt=q.front().second;
    
        q.pop();
        makeArr(now_num); //now_num에 해당하는 2차원 배열로 갱신

        if(checkSame()){ //9칸이 같은 면이면 횟수 반환
            return cnt;
        }

        //총8번 (행 뒤집기 3번, 열 뒤집기 3번, 대각선 뒤집기 2번)
        for(int i=0; i<8; i++){ //뒤집은 후 나오지않은경우면 q에넣고, 뒤집은건 원위치 해야함.
            if(i<3){ //행 뒤집기
                flipRow(i);
            }else if(i<6){ //열 뒤집기
                flipCol(i%3);
            }else{
                flipCross(i); //대각선 뒤집기
            }

            //뒤집은 상태를 10진법으로
            int next_num=makeNum();

            //방문하지 않았을때만 queue에 넣기
            if(!visit[next_num]){
                visit[next_num]=true;
                q.push({next_num,cnt+1});
            }

            //filp과정 똑같이 한번 더해주면 원상태로 된다.
            if(i<3){
                flipRow(i);
            }else if(i<6){
                flipCol(i%3);
            }else{
                flipCross(i);
            }
        }
    }

    return -1; //모든경우 다했을때 return 안되면 불가능한경우임.
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>tc;
    for(int t=0; t<tc; t++){
        int now_num=0; //현재 배열상태를 10진법으로 표현한 수
        memset(visit,false,sizeof(visit)); //visit배열 초기화
        
        //배열 입력
        //T는 1, H는 0으로 저장
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                char c;
                cin>>c;
                if(c=='T')
                    arr[i][j]=1;
                else
                    arr[i][j]=0;
                
                now_num=now_num*2+arr[i][j];
            }
        }
        visit[now_num]=true; //처음상태 방문체크

        cout<<bfs(now_num,visit)<<"\n"; //정답
        

    }


}