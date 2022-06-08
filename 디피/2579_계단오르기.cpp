//2579. 계단 오르기
#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[301]; //계단 배열
int d[301][301]; //디피 저장
int answer; //정답

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    d[1][0]=arr[1];
    d[2][0]=arr[2];
    d[2][1]=d[1][0]+arr[2];


    for(int i=3; i<=n; i++){
        d[i][i-2]=max(d[i-2][i-4],d[i-2][i-3])+arr[i];
        d[i][i-1]=d[i-1][i-3]+arr[i];
    }
    answer=max(d[n][n-2],d[n][n-1]);
    cout<<answer<<"\n";



}