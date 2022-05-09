//9095번: 1,2,3더하기

/*
풀이
d[n]: n을 나타내는 방법의 수

d[n]은 다음 세 경우의 합으로 구할 수 있다.
1) n-1을 만들고 뒤에 1을 더하는 방법의 수
2) n-2을 만들고 뒤에 2를 더하는 방법의 수
3) n-3을 만들고 뒤에 3을 더하는 방법의 수

그래서 점화식은 다음과 같다
d[n] = d[n-1] + d[n-2] + d[n-3]


*/
#include <iostream>
using namespace std;

int d[12];

int func(int n){
    if(n==1)
    return d[1]=1;

    if(n==2)
    return d[2]=2;

    if(n==3)
    return d[3]=4;

    if(d[n]>0)
    return d[n];

    return d[n]=func(n-1)+func(n-2)+func(n-3);
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        cout<<func(n)<<"\n";
    }
}
