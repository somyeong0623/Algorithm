//16967번: 배열 복원하기
//몰라서 구글링함... 아직 안푼 상태

/*
H, W, X, Y
2<=H,W<=300
1<=X<H
1<=Y<W
0<=B(i,j) <=1,000

*/
#include <iostream>
using namespace std;
int arr[600][600]; //주어지는 배열
int answer[300][300]; //정답 배열
int h,w,x,y;

int main(){
    cin>>h>>w>>x>>y;

    int new_h= h+x;
    int new_w= w+y;

    for(int i=0; i<new_h; i++){
        for(int j=0; j<new_w; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
          answer[i][j]=arr[i][j];
        }
    }

    for(int i=x; i<h+x; i++){
        for(int j=y; j<w+y; j++){
            answer[i][j]=answer[i][j]-answer[i-x][j-x]; //여기 잘 이해안감
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}