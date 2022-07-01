//2630.색종이 만들기
/*
N: 2,4,8,16,32,64,128 중 하나
하얀색: 0
파란색: 1
하얀색 색종이갯수, 파란색 색종이 갯수 출력

*/
#include <iostream>
using namespace std;
int n;
int arr[129][129];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

}