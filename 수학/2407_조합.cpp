#include <iostream>
using namespace std;

int n,m;
long long child=1, parent=1;
long long answer;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        child*=(n-i);
        parent*=(i+1);
    }
    // cout<<"parent= "<<parent<<"\n";
    // cout<<"child= "<<child<<"\n";  
    answer=child/parent;
    cout<<answer<<"\n";
}