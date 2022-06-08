#include <iostream>
using namespace std;


int n;
int d[1001];


int main(){
    cin>>n;
    d[1]=1;
    d[2]=3;

   

    for(int i=3; i<=n; i++){
        d[i]=d[i-2]*2+d[i-1];
    }

    cout<<d[n]<<"\n";
}