//15990번: 1,2,3 더하기 5

/*
풀이
d[i][j]: i을 만드는 방법의 수, 단 마지막 숫자는 j여야함.


*/

#include <iostream>
#define NUM 1000000009
using namespace std;

long long d[100001][4];
long long dp[100001];

int func(int n){
    if(dp[n])
    return dp[n];

    for(int i=4; i<=n; i++){
    d[i][1]=(d[i-1][2]+d[i-1][3])%NUM;
    d[i][2]=d[i-2][1]+d[i-2][3]%NUM;
    d[i][3]=d[i-3][1]+d[i-3][2]%NUM;
    }

    return dp[n]=(d[n][1]+d[n][2]+d[n][3])%NUM;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    dp[1]=1;
    dp[2]=1;
    dp[3]=3;

    d[1][1]=1;
    d[2][2]=1;
    d[3][3]=1;

    d[1][2]=0;
    d[1][3]=0;
    d[2][1]=0;
    d[2][3]=0;
    d[3][1]=1;
    d[3][2]=1;
    


    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        cout<<func(n)<<"\n";
    }
}