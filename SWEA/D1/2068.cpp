#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;

int main(){
    cin>>t;
    for(int i=1; i<=t; i++){
    vector<int> v;

        cout<<"#"<<i<<" ";
        
        for(int j=0; j<10; j++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        cout<<v[9]<<"\n";
       


    }
}