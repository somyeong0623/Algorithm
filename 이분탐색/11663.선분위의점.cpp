//11663. 선분 위의 점
/*
점의 갯수 N
선분의 갯수 M
1<=N,M<=100,000
모든 좌표: 1,000,000,000보다 작거나 같은 자연수

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
vector<int> point;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){ //점의 좌표
        int x;
        cin>>x;
        point.push_back(x);
    }

    sort(point.begin(),point.end());
    for(int i=0; i<m; i++){
        int st;
        int en;

        cin>>st>>en;
        int cnt=upper_bound(point.begin(),point.end(),en)-lower_bound(point.begin(),point.end(),st);
        //각 bound들은 iterator이다.
        cout<<cnt<<"\n";
    }
    
}