//9095번: 1,2,3 더하기
#include <iostream>
using namespace std;

int answer[11];
int t,n;

int func(int n){
    if(n==1)
    return 1;
    if(n==2)
    return 2;
    if(n==3)
    return 4;

    for(int i=4; i<=n; i++){
        if(answer[i])
        continue;
        answer[i]=answer[i-1]+answer[i-2]+answer[i-3];

    }
    return answer[n];

}

int main(){
    answer[1]=1;
    answer[2]=2;
    answer[3]=4;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<func(n)<<"\n";

    }
    

}

############################################

//9095번:1,2,3더하기 - 재귀함수 이용
#include<iostream>
using namespace std;

int t,n;
int answer=0;
void func(int cnt, int sum, int goal){
    if(sum>goal)
    return;

    if (sum==goal){
        answer++;
         return;
    }

    for(int i=1; i<=3; i++){
        func(cnt+1,sum+i,goal);
    }
}
//cnt는 의미없어서 없애도 됨.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    while(t--){
        cin>>n;
        answer=0;
        func(0,0,n);
        cout<<answer<<"\n";
    }

}
