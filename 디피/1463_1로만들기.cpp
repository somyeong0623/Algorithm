//1463번: 1로 만들기
#include <iostream>
#include <cmath>
using namespace std;

int n;
int dp[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin>>n;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    for(int i=5; i<=n; i++){

        dp[i]=dp[i-1]+1;

        if(i%3==0){
            dp[i]=min(dp[i/3]+1, dp[i]);
        }
        if(i%2==0){
            dp[i]=min(dp[i/2]+1, dp[i]);
        }
        
    }
    cout<<dp[n]<<"\n";
    
}