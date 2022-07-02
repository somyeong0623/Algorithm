//1920. 수 차기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;

bool func(int x, vector<int> &v){
    int st=0;
    int en=n-1;
    int mid=0;
    while(st<=en){
        mid=(st+en)/2;
        // cout<<"mid: "<<mid<<"\n";
        if(v[mid]==x){
            return true;
        }else if(v[mid]<x){
            st=mid+1;
        }else{
            en=mid-1;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<int> v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    cin>>m;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        cout<<func(x,v)<<"\n";
    }


}