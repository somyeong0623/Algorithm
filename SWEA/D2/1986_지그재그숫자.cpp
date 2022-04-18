/*
1~N까지 홀수는 더하고 짝수는 뱀.
1<=N<=10

*/

#include<iostream>
using namespace std;

int main(){
    int T;
    int sum;

    cin>>T;
    for(int i=1; i<=T; i++){
        int n;
        cin>>n;
        sum=0;
        for(int j=1; j<=n; j++){
            if(j%2==1){
                sum+=j;
            }else{
            sum-=j;
            }
        }

        cout<<"#"<<i<<" "<<sum<<"\n";
    }
}