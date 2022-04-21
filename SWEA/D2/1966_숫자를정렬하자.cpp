#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int TC; 
int n,x;
vector<int> v;
int main(){
    cin>>TC;
    for(int i=1; i<=TC; i++){
        v.clear();

        cin>>n;
        for(int j=0; j< n; j++){
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        
        cout<<"#"<<i<<" ";
        for(int j=0; j<v.size(); j++){
            cout<<v[j]<<" ";
        }
        cout<<"\n";
    }
}