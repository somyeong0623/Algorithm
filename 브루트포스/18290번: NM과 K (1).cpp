//18290번: NM과 K (1)
#include <iostream>
using namespace std;

int arr[10][10];
bool check[10][10];
int answer=-40000; //입력받는 수의 최솟값은 -10000이고 k는 최대 4이므로 sum의 최솟값인-10000*4=-40000을 answer로 설정. 
int n,m,k;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};


void func(int cnt, int sum){
    if(cnt==k){
        if(answer<sum)
        answer=sum;
        return;
    }
    for(int x=0; x<n; x++){
        for(int y=0; y<m; y++){
            if(check[x][y]) // 사용 중복 확인.
                continue;
            
            bool flag= true; //조건 부합 여부 체크
            
            for(int i=0; i<4; i++){ //인접한 칸 사용했는지 검사
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(check[nx][ny])
                        flag=false;
                    }

            }
            //arr[x][y] 해당하는수가 이미 사용되었거나, 그 인접칸이 사용되었을 경우 pass하고 다음 for문으로 이동.
            if(flag){ //조건 통과된 경우 (flag==true)
                check[x][y]=true;
                func(cnt+1,sum+arr[x][y]);
                check[x][y]=false;
            }
            
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
        cin>>arr[i][j];
    }

    func(0,0);
    cout<<answer<<"\n";
}

/////////////////////////////////////////////
//18290번: NM과 K (1) - 시간복잡도 더 줄인 풀이
#include <iostream>
using namespace std;

int arr[10][10];
bool check[10][10];
int answer=-40000; //입력받는 수의 최솟값은 -10000이고 k는최대 4 이므로 sum의 최솟값인-10000*4=-40000을 answer로 설정함.
int n,m,k;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};


//좌표하나를 정하고 ,다음 좌표를 정할때 for문 처음부터 돌게되면 안봐도 되는부분까지 또 검사하게 됨.
//이전 좌표의 다음 위치에 있는 좌표들만 검사하면 됨.
void func(int prev_x,int prev_y,int cnt, int sum){ //매개변수 prev_x, prev_y 추가
    if(cnt==k){
        if(answer<sum)
        answer=sum;
        return;
    }
    for(int x=prev_x; x<n; x++){ //prev_x : 이전에 선택된 수의 x좌표, prev_y:이전에 선택된 수의 y좌표. 
        for(int y=(prev_x==x?prev_y:0); y<m; y++){ //prev_x와 x가 같으면 prev_v이후의 y값부터 검사, prev_x<x(즉, prevx_x!=x)이면 y는 인덱스0부터 검사
            //prev_y -> prev_y+1도 상관없긴함.(check에서 걸러짐)
            if(check[x][y]) // 사용 중복 확인.
                continue;
            
            bool flag= true;  //조건 부합 여부 체크.
            for(int i=0; i<4; i++){ //인접한 칸 사용했는지 검사
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(check[nx][ny])
                        flag=false;
                    }

            }
            //arr[x][y] 해당하는수가 이미 사용되었거나, 그 인접칸이 사용되었을 경우 pass하고 다음칸부터 다시 검사
            if(flag){ //조건 통과된 경우
                check[x][y]=true;
                func(x,y,cnt+1,sum+arr[x][y]);
                check[x][y]=false;
            }
            
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
        cin>>arr[i][j];
    }

    func(0,0,0,0);
    cout<<answer<<"\n";
}
