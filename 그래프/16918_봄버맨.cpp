//16918.봄버맨
#include <iostream>
#include <algorithm>
using namespace std;

char arr[200][200];
char arr_copy[200][200];
int r,c,n;// 행, 열, 초
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};

void copy1(){ //arr를 arr_copy에
      for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            arr_copy[i][j]=arr[i][j];
        }
    }
}
void copy2(){//arr_copy를 arr에
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            arr[i][j]=arr_copy[i][j];
        }
    }
}

void fill(){ //배열 전체에 폭탄 채우기
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            arr[i][j]='O';
        }
    }
}

void bomb(){ //폭탄 터뜨리기 (+인접 폭탄도)

     for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(arr_copy[i][j]=='O'){ //arr_copy 배열 바탕으로 arr배열 터뜨리기
                int cur_r=i;
                int cur_c=j;
                arr[cur_r][cur_c]='.'; //해당자리 터뜨리기
                for(int k=0; k<4; k++){
                    int nr=cur_r+dr[k];
                    int nc=cur_c+dc[k];
                    if(nr>=0 && nr<r && nc>=0 && nc<c){
                        arr[nr][nc]='.';
                    }
                }
            }
        }
     }
     copy1(); //arr_copy에 결과 갱신
}

void print(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>r>>c>>n;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
        }
    }

    copy1(); //arr_copy에 arr정보 복사
    for(int i=1; i<=n; i++){
        if(i==1){
            continue;
        }
        if(i%2==0){ //짝수초 후
            fill();
        }else{ //홀수초 후
            bomb();
        }

        // print();
    }


    print();
}