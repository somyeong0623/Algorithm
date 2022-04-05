//1182번: 부분수열의 합

/* 

N,S
1 <= N <= 20
|S| <= 1,000,000
합이 s가 되는 부분수열의 갯수 출력

 */

#include <iostream>
#include <cmath>
using namespace std;

int n,s;
int arr[21];
int cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    int total= pow(2,n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<total ; i++){
        int sum=0;
        for(int k=0; k<n; k++){
            if(i&(1<<k)){
            sum+=arr[k];
            }
        }

        if(sum==s){
            // cout<<"i : "<<i<<"\n";
            cnt++;
        }
    }

    cout<<cnt<<"\n";
}


