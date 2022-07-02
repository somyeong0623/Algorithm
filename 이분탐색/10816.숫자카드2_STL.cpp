//10816. 숫자 카드 2(STL이용)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<int> v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    cin>>m;
    while(m--){
        int x;
        cin>>x;
        cnt=upper_bound(v.begin(),v.end(),x)-lower_bound(v.begin(),v.end(),x);
        cout<<cnt<<" ";
    }
}