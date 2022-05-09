//16194번: 카드 구매하기2
#include <iostream>
#include <cmath>
using namespace std;

int p[1001];
int d[1001];

int main(){
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>p[i];
    }

    d[0]=0;
    d[1]=p[1];

    for(int i=2; i<=n; i++){
        d[i]=p[i];
        for(int j=0; j<=i-1; j++){
            int temp=d[j]+p[i-j];
            if(d[i]>temp){
                d[i]=temp;
                cout<<"i: "<<i<<", j: "<<j<<"\n";
                cout<<"temp: "<<temp<<"\n";
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<d[i]<<" ";
    }


    cout<<d[n]<<"\n";
}