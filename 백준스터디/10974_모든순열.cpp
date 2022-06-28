//10974. 모든 순열
//백트래킹으로 어떻게 푸는지 모르겠다 ....
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
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }

    sort(v.begin(),v.end());

    do{
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }while(next_permutation(v.begin(),v.end()));
    
}