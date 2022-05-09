//11726번: 2xn 타일링
#include <iostream>
using namespace std;

int d[10001];
int n;

int dp1(int n){
    if(n==1)
    return d[1]=1;

    if(n==2)
    return d[2]=2;

    if(d[n]!=0)
    return d[n];

    return d[n]=dp1(n-1)+dp1(n-2);
}

int main(){
    cin>>n;
    cout<<dp1(n)<<"\n";
}