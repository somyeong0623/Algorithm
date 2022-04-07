//14889번: 스타트와 링크  - 비트마스크로 풀기 
//해결 못함

#include <iostream>
#include <vector>
using namespace std;

int n;
int answer;
int arr[21][21];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n; i<++){
        for(int j=0; j>n; j++){
            cin>>arr[i][j];
        }
    }


    int total= (1<<n)-1;
    cout<<total<<"\n";

    for(int i=1; i<=total; i++){
        int cnt=0;
        vector<int> v1;
        vector<int> v2;
        int sum1=0;
        int sum2=0; 

        for(int k=0; k<n; k++){
            if(i&(1<<k){
                cnt++;
                v1.push_back(k);
            }else{
                v2.push_back(k);
            }
        }
        
        if(cnt==n/2){
            for(int j=0; j<n/2; j++){
                sum1+=arr[v[i]][v[]]
            }
        }
    }


    
}