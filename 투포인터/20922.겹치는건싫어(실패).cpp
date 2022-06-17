//20922번: 겹치는건 싫어
/*
1<=N<=200,000
1<=K<=100

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n,k;
int arr[200005];
int cnt[100005];
int answer;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int st=0; //en먼저 움직이다가 en못움직일때 st움직이는 방법!
    int en=0;
    cnt[arr[en]]=1; //현재 카운트
    while(en<n){
        if(cnt[arr[en+1]]>=k){ //다음 전진할 칸인 arr[en+1]이 k번 이상 나온상태면 en은 멈추고 st움직인다.
            cnt[arr[st]]--; // arr[st]횟수하나 줄이고
            st++;   //앞으로 한칸 전진
            cnt[arr[st]]++; //전진한 칸의 숫자 세기
        }else{  //arr[en] 갯수가 k보다 작거나 같으면 en으로 계속간다
            en++;   // en 한칸 전진
            cnt[arr[en]]++; // 전진한 칸의 숫자 세기

        }
        
        if(en-st+1>answer){
            answer=en-st+1;
           
        }
        //  cout<<"en: "<<en<<" st: "<<st<<" ,answer: "<<answer<<"\n";

    }

   

    cout<<answer<<"\n";
}