//1463. 1로 만들기
#include <iostream>
using namespace std;

int n;
int d[1000001];

int main(){
    cin>>n;
    d[1]=0;
    d[2]=1;
    d[3]=1;
    
    for(int i=4; i<=n; i++){
        d[i]=d[i-1]+1;

        if(i%3==0){
            if(d[i/3]+1 <d[i])
                d[i]=d[i/3]+1;
        }
        if(i%2==0){
            if(d[i/2+1<d[i]])
                d[i]=d[i/2]+1;
        }
    }

    cout<<d[n]<<"\n";


}