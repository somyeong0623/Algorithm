/*
10<=N<=1,000,000
50,000 10,000 5,000 1,000 500 100 50 10

*/

#include <iostream>
#include <string.h>
using namespace std;

int TC,n;
int cnt[8];

int main(){
    cin>>TC;

    for(int i=1; i<=TC; i++){
        memset(cnt,0,sizeof(cnt));

        int n;
        cin>>n;
        //일의 자리 제거
        n=n/10*10;

        while(n!=0){
            if(n>=50000){
                cnt[0]=n/50000;
                n=n%50000;
            }else if(n>=10000){
                cnt[1]=n/10000;
                n=n%10000;
            }else if(n>=5000){
                cnt[2]=n/5000;
                n=n%5000;
            }else if(n>=1000){
                cnt[3]=n/1000;
                n=n%1000;
            }else if(n>=500){
                cnt[4]=n/500;
                n=n%500;
            }else if(n>=100){
                cnt[5]=n/100;
                n=n%100;
            }else if(n>=50){
                cnt[6]=n/50;
                n=n%50;
            }else{ //10원 단위
                cnt[7]=n/10;
                n=n%10;
            }
        }
        
        
        cout<<"#"<<i<<"\n";
        for(int j=0; j<8; j++){
            cout<<cnt[j]<<" ";
        }
        cout<<"\n";

    }
}