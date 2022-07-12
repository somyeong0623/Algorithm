//2630. 색종이 만들기
/*
N= 2,4,8,16,32,64,128 중 하나.
하얀색 0, 파란색 1
하얀색(0) 갯수, 파란색(1) 갯수 순서로 출력
*/
#include <iostream>
using namespace std;

int n;
bool arr[129][129];
int white,blue;

void func(int y, int x, int n){ //길이 n부터 시작해서, 정사각형이 아닐때마다 1/2로 줄어든다
    int tmp=0; //파란색 정사각형 임시 갯수
    for(int i=y; i<y+n; i++){
        for(int j=x; j<x+n; j++){
            if(arr[i][j]){//파란색이면
                tmp++;
            }
        }
    }

    if(tmp==n*n){ //전체가 파란색일 경우
        blue++;
    }else if(tmp==0){//전체가 하얀색일 경우
        white++;
    }else{ //파란색,하얀색이 정사각형 모양으로 안나오는 경우

        //항상 이 네가지의 정사각형이 생성된다.
        func(y,x,n/2);
        func(y+n/2,x,n/2);
        func(y,x+n/2,n/2);
        func(y+n/2,x+n/2,n/2);
    }
    // return;//여기 return의 의미?
 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    func(0,0,n); //시작점의 y좌표, x좌표, 색종이 길이

   cout<<white<<"\n"<<blue<<"\n";
}   