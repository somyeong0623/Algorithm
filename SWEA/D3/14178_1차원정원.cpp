/*
[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스는 하나의 줄로 이루어진다. 각 줄에는 두 개의 정수 N과 D (1 ≤ N, D ≤ 100) 가 공백 하나를 사이로 두고 주어진다.

[출력]
각 테스트 케이스마다 모든 꽃이 한 개 이상의 분무기에서 물을 받을 수 있도록 하기 위해 필요한 최소한의 분무기 수를 출력한다.
*/
#include <iostream>
using namespace std;

int TC;
int n,d;
int answer=0;

int main(){
    cin>>TC;
    for(int t=1; t<=TC; t++){
        cin>>n>>d;
        int range=d*2+1; //분무기 하나로 몇개 물을줄수 있는 꽃의 갯수
        if(n%range==0){ //나머지가 없으면 딱 맞게 물을 줄 수 있음
            answer=n/range;
        }else{
            answer=n/range+1; //나머지가 있으면 추가로 하나의 분무기가 더 필요하다
        }
        cout<<"#"<<t<<" "<<answer<<"\n";
    }
    
}