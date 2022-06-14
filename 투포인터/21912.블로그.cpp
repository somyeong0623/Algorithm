//21921. 블로그
/*
1<=x<=n<=250,000
0<=방문자수<=8,000

*/
#include <iostream>
using namespace std;

int n,x;
int temp; //x일 동안 방문자수 합 저장
int max_temp; //최대 방문자수
int cnt; //x일동안 최대 방문자수인 기간 갯수
int arr[250005]; 



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //처음 x일 동안 방문자수
    for(int i=0; i<x; i++){
        temp+=arr[i];
    }
    cnt=1;
    max_temp=temp;

    //한칸씩 밀기
    for(int i=x; i<n; i++){
        temp-=arr[i-x];
        temp+=arr[i];

        if(temp>max_temp){
            cnt=1;
            max_temp=temp;
        }else if(temp==max_temp){
            cnt++;
        }

    }

    if(max_temp==0){
        cout<<"SAD"<<"\n";
    }else{
        cout<<max_temp<<"\n";
        cout<<cnt<<"\n";
    }


}