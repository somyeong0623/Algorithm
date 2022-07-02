//10816. 숫자 카드 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int cnt;

// void bt(int x,vector<int> &v){
//     int st=0;
//     int en=n-1;
//     int mid=0;

//     while(st<=en){
//         mid=(st+en)/2;
//         if(v[mid]==x){
//             cnt[x]++;
//         }else if(v[mid]>x){
//             en=mid-1;
//         }else{
//             st=mid+1;
//         }
//     }
// }



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