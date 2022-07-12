//15649.N과 M(1)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        v[i]=i+1;
    }

    do{
        for(int i=0; i<m; i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }while(next_permutation(v.begin(),v.end()));


}