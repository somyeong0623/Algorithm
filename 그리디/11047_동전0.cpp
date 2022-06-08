//11047번: 동전 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
int answer;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    for(int i=0; i<v.size(); i++){
        if(v[i]<=k){
            answer+=k/v[i];
            k%=v[i];
        }

        if(k==0)
            break;

    }
    cout<<answer<<"\n";
}