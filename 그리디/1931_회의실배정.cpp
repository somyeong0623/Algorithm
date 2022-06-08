//1931. 회의실 배정 (몰라서 구글링함))
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].second>>v[i].first;
    }
    
    sort(v.begin(), v.end()); //회의의 종료시점을 기준으로 정렬
    
    int cnt=1;
    int time=v[0].first;
    for(int i=1; i<n; i++){
        if(time<=v[i].second){
            cnt++;
            time=v[i].first;
        }
    }
    cout<<cnt<<"\n";

}