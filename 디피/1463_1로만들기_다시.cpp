//1463번: 1로 만들기

/*
풀이 방법
d[n]= min(d[n/3],d[n/2],d[n-1])+1 라는 점화식이 성립한다.
식 그대로 함수로 구현하면 된다.
*/

#include <iostream>
#include <cmath>
using namespace std;


int n;
int d[1000001];

//top-down 방식
int dp1(int n){

    //초기값. d[n]=1;
    if(n==1)
    return 0;

    //비교할 값을 3방법중에 하나로 선택하여 먼저 실행.
    //3방법중에 어떤거 먼저할지는 상관 없음.
    d[n]=dp1(n-1)+1;

    if(n%3==0){ 
        int value = d[n/3]+1;
        if(d[n]>value){
            d[n]=value;
        }
    }

    if(n%2==0){
        int value=d[n/2]+1;
        if(d[n]>value){
            d[n]=value;
        }
    }
    //이때 6과같이 2로도 나누어떨어지고 3으로도 나누어 떨어질수 있는 수도 있으므로
    //두 if문을 if, else if로 나누면안되고 각각if 문으로 선언해야한다.


    return d[n];
}

//bottom-up 방식
int dp2(int n){
    d[1]=0;

    for(int i=2; i<=n; i++){
        d[i]=d[i-1]+1;

        if(i%3==0){
            int temp=d[i/3]+1;
            if(d[i]>temp){
                d[i]=temp;
            }
        }

        if(i%2==0){
            int temp=d[i/2]+1;
            if(d[i]>temp){
                d[i]=temp;
            }
        }

    }

    return d[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin>>n;
    // cout<<dp(n)<<"\n";
    cout<<dp2(n)<<"\n";
}