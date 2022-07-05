//16234. 인구 이동
/*
1<=N<=50
1<=L<=R<=100
0<=people[r][c]<=100
인구이동 발생하는 일수 <= 2000
인구 이동이 며칠 동안 발생하는지 출력

*/
#include <iostream>
using namespace std;

int n,l,r;
int people[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>l>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>people[i][j];
        }
    }
}