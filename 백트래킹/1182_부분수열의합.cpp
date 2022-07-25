//1182. 부분수열의 합
/*
1<=n<=20
|s|<=1000,000

*/
#include <iostream>
using namespace std;

int n,s;
int cnt; //정답
int arr[21];

void func(int end, int sum){ //몇번째 원소까지 확인할지, 현재까지 합
    if(end==n){
        if(sum==s){
            cnt++;
        }
        return;

    }

    func(end+1, sum); //현재 원소 비포함 포함
    func(end+1,sum+arr[end]); //현재 원소 포함 (합 갱신))


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    func(0,0); //몇번째 원소까지 확인할지, 현재 합
    if(s==0){
        cnt--; //s=0이면 공집합도 포함되어있어서 1빼줘야함.
    }
    cout<<cnt<<"\n";



}