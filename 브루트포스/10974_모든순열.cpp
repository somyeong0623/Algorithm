//10974번: 모든순열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        v.push_back(i+1);
    }
    do{
        for(int i=0; i<n;i ++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";

    }while(next_permutation(v.begin(),v.end()));



}