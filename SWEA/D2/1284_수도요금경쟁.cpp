/*
[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스마다 첫 번째 줄에 위 본문에서 설명한 대로 P, Q, R, S, W(1 ≤ P, Q, R, S, W ≤ 10000, 자연수)가 순서대로 공백 하나로 구분되어 주어진다.

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 종민이가 내야 하는 수도 요금을 출력한다.
*/

#include <iostream>
using namespace std;
int TC;
int p,q,r,s,w;
int a,b; //a회사 요금, b회사 요금

int func(){
    a=p*w;
    b=0;

    if(w<=r){
        b=q;
    }else{
        b=q+s*(w-r);
    }

    if(a>b){
        return b;
    }else{
        return a;
    }
    
}


int main(){
    cin>>TC;
    for(int i=1; i<=TC; i++){
        cin>>p>>q>>r>>s>>w;
        
        cout<<"#"<<i<<" "<<func()<<"\n";

    }

}