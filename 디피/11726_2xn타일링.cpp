//11726번: 2xn 타일링
/*
몇개 그려서 해보면
d[n]은 d[n-1]에서 2*1 모양 도형을 오른쪽 끝에 붙인것과 
d[n-2]에서 2*2 모양 도형을 오른쪽 끝에 붙인것의 합과 같다.

*/


#include <iostream>
using namespace std;

int d[10001];
int n;

//top-down
int dp1(int n){
    if(n==1)
    return d[1]=1;

    if(n==2)
    return d[2]=2;

    if(d[n]!=0)
    return d[n];

    return d[n]=(dp1(n-1)+dp1(n-2))%10007;
}

//bottom-up
int dp2(int n){
    d[1]=1;
    d[2]=2;

    for(int i=3; i<=n; i++){
        d[i]=(d[i-1]+d[i-2])%10007;
    }

    return d[n];
}


int main(){
    cin>>n;
    // cout<<dp1(n)<<"\n";
    cout<<dp2(n)<<"\n";
}