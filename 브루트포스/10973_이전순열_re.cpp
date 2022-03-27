//10973번: 이전순열 _ 다른방법
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 


vector <int> v;
int n;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    if(prev_permutation(v.begin(),v.end())){
        for(int i=0; i<n; i++){
            cout<<v[i]<<" ";
        }
    }else{
           for(int i=0; i<n; i++){
            cout<<v[i]<<" ";
        }
        cout<<-1<<"\n";
    }

}